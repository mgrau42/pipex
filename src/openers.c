/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:08:01 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 14:15:01 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/pipex.h"

int	file_opener(char *infile, char *outfile, int hdoc_enabled, t_cmd *cmd)
{
	int	readfile;
	int	writefile;

	readfile = read_open(infile, hdoc_enabled);
	writefile = write_open(outfile, hdoc_enabled);
	if (writefile < 0 || readfile < 0)
		return (-1);
	assing_in_out_fd(cmd, readfile, writefile);
	return (0);
}

int	read_open(char *infile, int hdoc_enabled)
{
	int	readfile;

	if (hdoc_enabled)
	{
		readfile = heredoc_opener(infile);
		if (readfile < 0)
			error_message(errno, "Open not succesful: ", infile);
	}
	else
	{
		readfile = open(infile, O_RDONLY);
		if (readfile < 0)
			error_message(errno, "Open not succesful: ", infile);
	}
	return (readfile);
}

int	write_open(char *outfile, int hdoc_enabled)
{
	int	writefile;

	if (hdoc_enabled)
	{
		writefile = open(outfile, O_CREAT | O_WRONLY | O_APPEND, 00644);
		if (writefile < 0)
			error_message(errno, "Open not succesful: ", outfile);
	}
	else
	{
		writefile = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 00644);
		if (writefile < 0)
			error_message(errno, "Open not succesful: ", outfile);
	}
	return (writefile);
}

void	assing_in_out_fd(t_cmd *cmd, int readfile, int writefile)
{
	if (cmd->fd_list[0] >= 0)
		close(cmd->fd_list[0]);
	cmd->fd_list[0] = readfile;
	while (cmd->nextcmd)
		cmd = cmd->nextcmd;
	if (cmd->fd_list[1] >= 0)
		close(cmd->fd_list[1]);
	cmd->fd_list[1] = writefile;
}

int	heredoc_opener(char *file)
{
	char	*line;
	int		fd;

	fd = open("/tmp/heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
		return (-1);
	write(1, "> ", 2);
	get_next_line(0, &line);
	while (!line || ft_strncmp(line, file, ft_strlen(line)))
	{
		ft_putstr_fd(line, fd);
		write(fd, "\n", 1);
		free(line);
		line = NULL;
		write(1, "> ", 2);
		get_next_line(0, &line);
	}
	free(line);
	close(fd);
	fd = open("/tmp/heredoc", O_RDONLY);
	return (fd);
}
