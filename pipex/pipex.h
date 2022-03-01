#ifndef PIPEX_H
# define PIPEX_H
#  include "manu_utils.h"
#  include<unistd.h>
#  include<stdio.h>
#  include<fcntl.h>
#  include<string.h>
#  include<errno.h>
#  include"../libft/libft.h"
#  include<stddef.h>
#  include <sys/wait.h>

char *get_pathname(char *arg, char* paths);
int create_probable_str(char **dest, char *arg, char *src, int i);
char* get_pathlocation(char **envp);
void close_fds(int *fd_list, int *fd_in_out);
void make_dups(int *new_stdin, int*new_stdout);
	
typedef struct s_cmd
{
	char 	**argv;
	int		argc;
	int 	fd_list[2];
	pid_t	sh_pid;
	int		*prev;
	struct s_cmd	*nextcmd;
}				t_cmd;

t_cmd	*new_cmd(char *cmd);
void del_cmd_lst(t_cmd *cmd);
t_cmd *ft_tokargs(int argc, char *argv[]);

typedef struct s_ppx
{
	char	*path;
	t_cmd	*cmd;
	int		heredoc;
}			t_ppx;

	void initialize(t_ppx *ppx,int *argc, char **argv[], char ***envp);
	void finisher(t_ppx *ppx);
	void redirect(t_cmd *current);
	void launcher(t_cmd *cmd,char *path,char **envp);
	int  executer(t_cmd **cmd,char *path,char **envp);
	int  file_opener(char *infile, char* outfile,int hdoc_enabled, t_cmd *cmd);
	void assing_in_out_fd(t_cmd *cmd,int readfile, int writefile);
	int  heredoc_opener(char * file);
	void pied_piper(t_cmd *cmd);
	int	read_open(char *infile, int hdoc_enabled);
	int	write_open(char *outfile, int hdoc_enabled);
#endif