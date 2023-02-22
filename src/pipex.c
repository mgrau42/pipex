/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:40:05 by mgrau             #+#    #+#             */
/*   Updated: 2023/02/22 12:29:06 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/pipex.h"

// main function
int	main(int argc, char *argv[], char **envp)
{
	// define local variables
	t_ppx	ppx;
	int		status;
	// initialize variables
	initialize(&ppx, &argc, &argv, &envp);
	// execute commands
	pied_piper(ppx.cmd);
	// open files for input and output redirection
	if (file_opener(argv[1], argv[argc - 1], ppx.heredoc, ppx.cmd) < 0)
	{
		// handle error
		finisher(&ppx);
		return (errno);
	}
	// execute the command list
	status = executer(&ppx.cmd, ppx.path, envp);
	// clean up resources
	finisher(&ppx);
	return (status);
}

// finisher function to clean up resources
void	finisher(t_ppx *ppx)
{
	// delete the command list
	del_cmd_lst(ppx->cmd);
	// remove the heredoc file
	if (ppx->heredoc)
		unlink("/tmp/heredoc");
}

// pied_piper function to set up pipes between commands
void	pied_piper(t_cmd *cmd)
{
	int	fd_tmp[2];
	// loop over the commands and set up pipes
	while (cmd->nextcmd)
	{
		pipe(fd_tmp);
		cmd->fd_list[1] = fd_tmp[1];
		cmd->nextcmd->fd_list[0] = fd_tmp[0];
		cmd->nextcmd->prev = cmd->fd_list;
		cmd = cmd->nextcmd;
	}
}

// initialize function to set up the ppx struct
void	initialize(t_ppx *ppx, int *argc, char **argv[], char ***envp)
{
	// check the number of command line arguments
	if (*argc < 5)
		exit(error_message(22, "Invalid number of args: ", *argv[0]));
	// get the PATH environment variable
	ppx->path = get_pathlocation(*envp);
	// check if the command includes a heredoc
	if (!ft_strncmp("here_doc", (*argv)[1], ft_strlen((*argv)[1])))
	{
		ppx->heredoc = 1;
		(*argv)++;
		(*argc)--;
	}
	else
		ppx->heredoc = 0;
	// tokenize the command line arguments into a command list
	ppx->cmd = ft_tokargs(*argc, *argv);
}

// close_fds function to close file descriptors
void	close_fds(int *fd_list, int *fd_in_out)
{
	if (fd_in_out != NULL)
		close(*fd_in_out);
	close(fd_list[0]);
	close(fd_list[1]);
}
