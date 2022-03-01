/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:32:31 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/01 11:37:19 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

t_cmd	*ft_tokargs(int argc, char *argv[])
{
	int		i;
	t_cmd	*cmd;
	t_cmd	*tmp;

	i = 2;
	cmd = new_cmd(argv[i++]);
	tmp = cmd;
	while (i < argc - 1)
	{
		tmp->nextcmd = new_cmd(argv[i]);
		tmp = tmp->nextcmd;
		if (!tmp)
		{
			del_cmd_lst(cmd);
			exit(error_message(errno, "Allocation error: ", "cmd_lst"));
		}
		i++;
	}
	return (cmd);
}

void	del_cmd_lst(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd->nextcmd;
		close_fds(cmd->fd_list, NULL);
		free_matrix(cmd->argv);
		free(cmd);
		cmd = tmp;
	}
}

t_cmd	*new_cmd(char *cmd)
{
	t_cmd	*new;

	if (!cmd)
		return (NULL);
	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!(new))
		return (NULL);
	new->argv = ft_split(cmd, ' ');
	new->argc = ft_strlen((void *)new->argv);
	new->fd_list[0] = -1;
	new->fd_list[1] = -1;
	new->prev = NULL;
	new->nextcmd = NULL;
	return (new);
}
