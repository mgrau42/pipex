/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:01:25 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 14:14:45 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	redirect(t_cmd *current)
{
	if (current->prev)
		close(current->prev[1]);
	if (current->nextcmd)
		close(current->nextcmd->fd_list[0]);
	if ((dup2(current->fd_list[0], STDIN_FILENO)) < 0)
		exit(error_message(127, "pipex: -> command not found:", " "));
	close(current->fd_list[0]);
	if ((dup2(current->fd_list[1], STDOUT_FILENO)) < 0)
		exit(error_message(127, "pipex: -> command not found", " "));
	close(current->fd_list[1]);
}

void	launcher(t_cmd *cmd, char *path, char **envp)
{
	pid_t	pid;
	char	*to_exec;

	while (cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			if (cmd->fd_list[0] < 0 || cmd->fd_list[1] < 0)
				exit(1);
			to_exec = get_pathname(cmd->argv[0], path);
			redirect(cmd);
			if (execve(to_exec, cmd->argv, envp) == -1)
				exit(127);
		}
		close(cmd->fd_list[0]);
		close(cmd->fd_list[1]);
		cmd->sh_pid = pid;
		cmd = cmd->nextcmd;
	}
}

int	executer(t_cmd **cmd, char *path, char **envp)
{
	t_cmd	*tmp;
	int		status;

	status = 0;
	launcher(*cmd, path, envp);
	tmp = *cmd;
	while (tmp)
	{
		waitpid(tmp->sh_pid, &status, 0);
		tmp = tmp->nextcmd;
	}
	return (WEXITSTATUS(status));
}
