#include"pipex.h"

int main (int argc, char *argv[], char **envp)
{
	t_ppx	ppx;
	int status;
	initialize(&ppx,&argc,&argv,&envp);
	pied_piper(ppx.cmd);
	if(file_opener(argv[1], argv[argc - 1], ppx.heredoc, ppx.cmd) < 0)
	{
		finisher(&ppx);
		return(errno);
	}
	status = executer(&ppx.cmd,ppx.path,envp);
	finisher(&ppx);
	return(status);
}

void finisher(t_ppx *ppx) 
{
	del_cmd_lst(ppx->cmd);
	if(ppx->heredoc)
		unlink("/tmp/heredoc");
}

void pied_piper(t_ms *cmd)
{
	int fd_tmp[2];

	while(cmd->nextcmd)
	{
		pipe(fd_tmp);
		cmd->fd_list[1] = fd_tmp[1];
		cmd->nextcmd->fd_list[0] = fd_tmp[0];
		cmd->nextcmd->prev = cmd->fd_list;
		cmd = cmd->nextcmd;
	}
}

void initialize(t_ppx *ppx,int *argc, char **argv[], char ***envp)
{
	if (*argc < 5) 														//comprobamos el numero de argumentos
		exit(error_message(22, "Invalid number of args: ", *argv[0]));
	ppx->path = get_pathlocation(*envp);								//a partir de envp conseguimos el string con los posibles paths
	if(!ft_strncmp("heredoc",(*argv)[1],ft_strlen((*argv)[1]))) 		// determinamos si ay un argumento here doc
	{
		ppx->heredoc = 1;
		(*argv)++;
		(*argc)--;
	}
	else
		ppx->heredoc = 0; 												//si no hay heredoc
	ppx->cmd = ft_tokargs(*argc,*argv);									// tokenizamos
}

void close_fds(int *fd_list, int *fd_in_out)
{
	if (fd_in_out != NULL)
		close(*fd_in_out);
	close(fd_list[0]);
	close(fd_list[1]);
}
