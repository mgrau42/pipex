#include"pipex.h"

t_ms *ft_tokargs(int argc, char *argv[])
{
	int i;
	t_ms	*cmd;
	t_ms	*tmp;

	i = 2;
	cmd = new_cmd(argv[i++]); //creo una lista de estructuras enlazada con un comando en cada una
	tmp = cmd;
	while(i < argc -1)
	{
		tmp->nextcmd = new_cmd(argv[i]); //para desplazarme por ella uso tmp, cmd contiene el primor eslabon
		tmp = tmp->nextcmd;
		if(!tmp)
		{
			del_cmd_lst(cmd);
			exit(error_message(errno,"Allocation error: ","cmd_lst"));
		}
		i++;
	}
	return(cmd);
}

void del_cmd_lst(t_ms *cmd)
{
	t_ms *tmp;
	while (cmd)
	{
		tmp = cmd->nextcmd;
		close_fds(cmd->fd_list, NULL);
		free_matrix(cmd->argv);
		free(cmd);
		cmd = tmp;
	}
}

t_ms	*new_cmd(char *cmd)
{
	t_ms	*new;

	if(!cmd)
		return(NULL);
	if (!(new = (t_ms *)malloc(sizeof(t_ms))))
		return(NULL);
	new->argv = ft_split(cmd, ' ');
	new->argc = ft_strlen((void *)new->argv);
	new->fd_list[0] = -1;
	new->fd_list[1] = -1;
	new->prev = NULL;
	new->nextcmd = NULL;
	return(new);
}
