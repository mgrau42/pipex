#include"pipex.h"
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include"../libft/libft.h"
#include<stddef.h>
#include <sys/wait.h>

char *get_pathname(char *arg, char* paths);
void init_c_argv(char *c_argv[],char *argv[],char *paths);
void child_1(char *argv[], char **envp,int *fd_list, int *infile);
unsigned int	ft_strcharcpy(char *dest, char *src, char until, unsigned int pos);
int create_probable_str(char **dest, char *arg, char *src, int i);
int get_pathlocation(char **envp);
void init_c_argv2(char *c_argv[],char *argv[],char *paths);
void child_2(char *argv[], char **envp, int *fd_list, int *outfile);

int main (int argc, char *argv[], char **envp)
{
	int fd_list[2];
	int pid;
	int infile;
	int outfile;										

	if (!(num_of_args(argc, 5, 5))) 					//comprobamos el numero de argumentos
		return(error_exit(22));
	if ((infile = open(argv[1],O_RDONLY)) == -1) 	// se abre el primer archivo
		return(error_exit(errno));
	if ((outfile = open(argv[4],O_WRONLY)) == -1) 	// se abre el primer archivo
		return(error_exit(errno));
	pipe(fd_list);
	if ((pid = fork()) == 0) {		
		close(outfile);					//hacemoss un fork, ahora hay dos procesos
		child_1(argv, envp,fd_list,&infile);	}						//nos ocupamos del proceso hijo
	else 
	{
		close(infile);
		if ((pid = fork()) == 0)
		{
										//hacemoss un fork, ahora hay dos procesos
			child_2(argv, envp,fd_list,&outfile);
		}	
	}	

	close(fd_list[0]);
	close(fd_list[1]);
	waitpid(pid, NULL, 0);
														// problema, si tengo error en el hijo como termino padre y viceversa
														// main se detiene mediante la funcion waitpid
														// child 1 ejecuta argv[2] invalid argument or succesfull exec
														// como introducir argv[1] como stdin
														// a la hora de pasar  salida final a argv[3] comprobar si puedo escribir en el

	return(0);
}

char *get_pathname(char *arg, char*paths)
{
	unsigned int i = 5;
	char *dest;

	dest = NULL;
	i = create_probable_str(&dest, arg, paths,i);
	while ((access(dest,X_OK)) == -1 && i < strlen(paths))
	{
		free(dest);
		i = create_probable_str(&dest, arg, paths,i);
	}
	return(dest);
}

int get_pathlocation(char **envp)
{
	int i;
	i = 0;
	while((ft_strncmp("PATH=",envp[i],5))) // we got the start location of the portion we want
		i++;
	return(i);	
}

int create_probable_str(char **dest, char *arg, char *src, int i)
{
	*dest = malloc(sizeof(char) * ft_strlen((src + i)) + ft_strlen(arg) + 2);
	i = ft_strcharcpy(*dest,(src + i),':',0) + i; 
	ft_strcat(*dest,"/");
	ft_strcat(*dest,arg);
	return(i);
}



unsigned int	ft_strcharcpy(char *dest, char *src, char until, unsigned int pos)
{
	unsigned int i;
	i = 0;
	if ((!dest) || (!src))
		return (0);
	while ((src[pos] != '\0' && src[pos] != until))
		dest[i++] = src[pos++];
	dest[i] = 0;
	return (++pos) ;
}


void init_c_argv(char *c_argv[],char *argv[],char *paths)
{
		//modifi this i need falgs, FLAGS!!!
		c_argv[0] = get_pathname(argv[2], paths);
		c_argv[1] = argv[1];
		c_argv[2] = NULL;
}

void init_c_argv2(char *c_argv[],char *argv[],char *paths)
{
		c_argv[0] = get_pathname(argv[3], paths);
		c_argv[1] = argv[4];
		c_argv[2] = NULL;
}

void child_1(char *argv[], char **envp, int *fd_list, int *infile)
{
	char **to_exec;

	to_exec = ft_split(argv[2],' ');
	if ((dup2(*infile,STDIN_FILENO)) == -1) 	// se abre el primer archivo
		error_exit(errno);
	if((dup2(fd_list[1],STDOUT_FILENO)) == -1) 	// se abre el primer archivo
		error_exit(errno);
	close(*infile);
	close(fd_list[0]);
	close(fd_list[1]);
	if (execve(get_pathname(to_exec[0],envp[get_pathlocation(envp)]),to_exec ,envp) == -1)
	{
		error_exit(errno);
		exit(0);
	}
}

void child_2(char *argv[], char **envp, int *fd_list, int *outfile)
{
	char **to_exec;

	to_exec = ft_split(argv[3],' ');
	if ((dup2(*outfile,STDOUT_FILENO)) == -1) 	// se abre el primer archivo
		error_exit(errno);
	if((dup2(fd_list[0],STDIN_FILENO)) == -1) 	// se abre el primer archivo
		error_exit(errno);;
	close(*outfile);
	close(fd_list[0]);
	close(fd_list[1]);
	if (execve(get_pathname(to_exec[0],envp[get_pathlocation(envp)]),to_exec ,envp) == -1)
	{
		error_exit(errno);
		exit(0);
	}
}

