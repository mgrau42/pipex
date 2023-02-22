/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:08:01 by mgrau             #+#    #+#             */
/*   Updated: 2023/02/22 12:22:59 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/pipex.h"

// Function to open input and output files, optionally handling here document
// infile - input file name
// outfile - output file name
// hdoc_enabled - flag indicating if here document is enabled
// cmd - structure containing command details
// Returns 0 on success, -1 on failure
int file_opener(char *infile, char *outfile, int hdoc_enabled, t_cmd *cmd)
{
    // Open input and output files
    int readfile = read_open(infile, hdoc_enabled);
    int writefile = write_open(outfile, hdoc_enabled);

    // Check if either file opening failed
    if (writefile < 0 || readfile < 0)
        return (-1);

    // Assign input and output file descriptors to command structure
    assing_in_out_fd(cmd, readfile, writefile);

    return (0);
}


// Function to open input file, optionally handling here document
// infile - input file name
// hdoc_enabled - flag indicating if here document is enabled
// Returns file descriptor on success, -1 on failure
int read_open(char *infile, int hdoc_enabled)
{
    int readfile;

    // If here document is enabled, open file using here document opener
    if (hdoc_enabled)
    {
        readfile = heredoc_opener(infile);
        if (readfile < 0)
            error_message(errno, "Open not successful: ", infile);
    }
    // Otherwise, open file using read only mode
    else
    {
        readfile = open(infile, O_RDONLY);
        if (readfile < 0)
            error_message(errno, "Open not successful: ", infile);
    }

    return readfile;
}

// Function to open output file, optionally handling here document
// outfile - output file name
// hdoc_enabled - flag indicating if here document is enabled
// Returns file descriptor on success, -1 on failure
int write_open(char *outfile, int hdoc_enabled)
{
    int writefile;

    // If here document is enabled, open file using append mode
    if (hdoc_enabled)
    {
        writefile = open(outfile, O_CREAT | O_WRONLY | O_APPEND, 00644);
        if (writefile < 0)
            error_message(errno, "Open not successful: ", outfile);
    }
    // Otherwise, open file using truncate mode
    else
    {
        writefile = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 00644);
        if (writefile < 0)
            error_message(errno, "Open not successful: ", outfile);
    }

    return writefile;
}


// Function to open the input and output files and assign file descriptors to cmd structure
void	assing_in_out_fd(t_cmd *cmd, int readfile, int writefile)
{
	// If the first file descriptor in the list is already open, close it
	if (cmd->fd_list[0] >= 0)
		close(cmd->fd_list[0]);

	// Assign the new read file descriptor to the first position in the list
	cmd->fd_list[0] = readfile;

	// Traverse the command list until the last command is found
	while (cmd->nextcmd)
		cmd = cmd->nextcmd;

	// If the last file descriptor in the list is already open, close it
	if (cmd->fd_list[1] >= 0)
		close(cmd->fd_list[1]);

	// Assign the new write file descriptor to the last position in the list
	cmd->fd_list[1] = writefile;
}

// Function to open a file for reading, either with regular read or heredoc
int	heredoc_opener(char *file)
{
	char	*line;
	int		fd;

	// Open a temporary file for writing
	fd = open("/tmp/heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
		return (-1);

	// Prompt the user to enter lines until the specified input string is found
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

	// Free the final line and close the temporary file for writing
	free(line);
	close(fd);

	// Open the temporary file for reading and return the file descriptor
	fd = open("/tmp/heredoc", O_RDONLY);
	return (fd);
}

