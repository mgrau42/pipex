#include"pipex.h"
int file_opener(char *infile, char* outfile,int hdoc_enabled, t_cmd *cmd)
{
	int readfile;
	int writefile;

	if (hdoc_enabled)
	{
		if ((readfile = heredoc_opener(infile)) < 0)
			error_message(errno,"Open not succesful: ",infile);
	}
	else
		if((readfile = open(infile,O_RDONLY)) < 0)
			error_message(errno,"Open not succesful: ",infile);
	if (hdoc_enabled)
	{
		if ((writefile = open(outfile,O_CREAT | O_WRONLY | O_APPEND, 00644)) < 0)
			error_message(errno,"Open not succesful: ",outfile);
	}
	else
		if((writefile = open(outfile,O_CREAT | O_WRONLY | O_TRUNC, 00644)) < 0)
			error_message(errno,"Open not succesful: ",outfile);
	if(writefile < 0 || readfile < 0)
		return(-1);
	assing_in_out_fd(cmd,readfile,writefile);
	return(0);
}

void assing_in_out_fd(t_cmd *cmd,int readfile, int writefile)
{
	if (cmd->fd_list[0] >= 0)
		close(cmd->fd_list[0]);
	cmd->fd_list[0] = readfile;
	while(cmd->nextcmd)
		cmd = cmd->nextcmd;
	if(cmd->fd_list[1] >= 0)
		close(cmd->fd_list[1]);
	cmd->fd_list[1] = writefile;			
}

int heredoc_opener(char * file)
{
	char* line;
	int		fd;

	if((fd = open("/tmp/heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0666)) < 0) //todo lectura y escritura no exec
		return(-1);
	write(1,"> ",2);
	get_next_line(0,&line);
	while(!line || ft_strncmp(line, file, ft_strlen(line)))
	{
		ft_putstr_fd(line,fd);
		write(fd,"\n",1);
		free(line);
		line = NULL;
		write(1,"> ",2);
		get_next_line(0,&line);
	}
	free(line);
	close(fd);
	fd = open("/tmp/heredoc", O_RDONLY);
	return(fd);
}
