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
	int get_pathlocation(char **envp);
	void close_fds(int *fd_list, int *fd_in_out);
	void make_dups(int *new_stdin, int*new_stdout);
	
typedef struct s_ms
{
	pid_t	sh_pid;
	char	*prompt;
	char	*str;
	char	*cmd;
	char	*lastcmd;
	char	*flag;
	int		state;
	int fd_list[2];
}				t_ms;
	void child_1(char *argv[], char **envp,t_ms *s);
	void child_2(char *argv[], char **envp, t_ms *s);
	void initialize(t_ms *s,int argc, char *argv[]);
#endif