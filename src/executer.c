/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:01:25 by mgrau             #+#    #+#             */
/*   Updated: 2023/02/22 11:57:48 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
** This function redirects standard input and output to the appropriate file
** descriptors, and closes file descriptors for commands that aren't the first
** or last in the pipeline.
** Input:
**   - current: a pointer to the command being executed
*/
void	redirect(t_cmd *current)
{
	// Close the write end of the pipe from the previous command
	if (current->prev)
		close(current->prev[1]);

	// Close the read end of the pipe from the next command
	if (current->nextcmd)
		close(current->nextcmd->fd_list[0]);

	// Redirect standard input to the read end of the pipe
	if ((dup2(current->fd_list[0], STDIN_FILENO)) < 0)
		exit(error_message(127, "pipex: -> command not found:", " "));

	// Close the read end of the pipe
	close(current->fd_list[0]);

	// Redirect standard output to the write end of the pipe
	if ((dup2(current->fd_list[1], STDOUT_FILENO)) < 0)
		exit(error_message(127, "pipex: -> command not found", " "));

	// Close the write end of the pipe
	close(current->fd_list[1]);
}

/*
** This function forks a new process for each command in the pipeline and
** executes the command in the child process. The parent process waits for
** all child processes to complete.
** Input:
**   - cmd: a pointer to the first command in the pipeline
**   - path: the value of the PATH environment variable
**   - envp: the environment variables for the command execution
*/
void	launcher(t_cmd *cmd, char *path, char **envp)
{
	pid_t	pid;
	char	*to_exec;

	while (cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			// Check that the file descriptors for the pipe are valid
			if (cmd->fd_list[0] < 0 || cmd->fd_list[1] < 0)
				exit(1);

			// Find the full path of the command
			to_exec = get_pathname(cmd->argv[0], path);

			// Redirect standard input and output to the pipe
			redirect(cmd);

			// Execute the command
			if (execve(to_exec, cmd->argv, envp) == -1)
				exit(127);
		}

		// Close the pipe file descriptors in the parent process
		close(cmd->fd_list[0]);
		close(cmd->fd_list[1]);

		// Store the child process ID for later use
		cmd->sh_pid = pid;

		// Move to the next command in the pipeline
		cmd = cmd->nextcmd;
	}
}

/*
** This function launches the pipeline and waits for all child processes to
** complete. It returns the exit status of the last command executed.
** Input:
**   - cmd: a pointer to the first command in the pipeline
**   - path: the value of the PATH environment variable
**   - envp: the environment variables for the command execution
** Output:
**   - the exit status of the last command executed
*/
int	executer(t_cmd **cmd, char *path, char **envp)
{
	t_cmd	*tmp;
	int		status;

	status = 0;

	// Launch the pipeline
	launcher(*cmd, path, envp);

	// Wait for all child processes to complete
	tmp = *cmd;
	while (tmp)
	{
		waitpid(tmp->sh_pid, &status, 0);
		tmp = tmp->nextcmd;
	}

	// Return the exit status of the last command executed
	return (WEXITSTATUS(status));
}
