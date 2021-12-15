#include"pipex.h"

int main (int argc, char *argv[], char **envp)
{
	int fd_list[2];
	int status;
	int pid;									

	if (!(num_of_args(argc, 5, 5))) 					//comprobamos el numero de argumentos
		error_exit(22, "Invalid number of args: ", argv[0], EXIT_FAILURE);
	pipe(fd_list);
	if ((pid = fork()) == 0)//hacemoss un fork, ahora hay dos procesos
		child_1(argv, envp,fd_list);					//nos ocupamos del proceso hijo
	else {
		if ((pid = fork()) == 0)								//hacemoss un fork, ahora hay dos procesos
			child_2(argv, envp,fd_list);
		close_fds(fd_list, NULL);
	}
		waitpid(pid, &status, 0);
	return(WEXITSTATUS(status));
}


void child_1(char *argv[], char **envp, int *fd_list)
{
	char **to_exec;
	int file_fd;
	char *temp;

	if ((file_fd = open(argv[1],O_RDONLY)) == -1) 	// se abre el primer archivo
			error_exit(errno,"Open not succesful: ", argv[1],EXIT_FAILURE);

	to_exec = ft_split(argv[2],' ');

	make_dups(&file_fd, &fd_list[1]);
	close_fds(fd_list, &file_fd);

	temp = get_pathname(to_exec[0],envp[get_pathlocation(envp)]);
	if (execve(temp, to_exec ,envp) == -1)
	{
		free(temp);
		free_matrix(to_exec);
		exit(127);
	}
}

void child_2(char *argv[], char **envp, int *fd_list)
{
	char **to_exec;
	char * temp;
	int file_fd;

	if ((file_fd = open(argv[4],O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1) 	// se abre el primer archivo
		error_exit(errno,"Open not succesful: ",argv[4], EXIT_FAILURE);

	to_exec = ft_split(argv[3],' ');

	make_dups(&fd_list[0], &file_fd);
	close_fds(fd_list, &file_fd);
	temp = get_pathname(to_exec[0],envp[get_pathlocation(envp)]);
	if (execve(temp,to_exec ,envp) == -1)
	{
		free(temp);
		free_matrix(to_exec);
		exit(127);
	}
}

void close_fds(int *fd_list, int *fd_in_out)
{
	if (fd_in_out != NULL)
		close(*fd_in_out);
	close(fd_list[0]);
	close(fd_list[1]);
}

void make_dups(int *new_stdin, int*new_stdout)
{
	if (dup2(*new_stdin,STDIN_FILENO) == -1) 	// se abre el primer archivo
		error_exit(errno,"dup2: -> STDIN error:"," ", EXIT_FAILURE);
	if(dup2(*new_stdout,STDOUT_FILENO) == -1) 	// se abre el primer archivo
		error_exit(errno,"dup2: -> STDOUT error:"," ", EXIT_FAILURE);
}

