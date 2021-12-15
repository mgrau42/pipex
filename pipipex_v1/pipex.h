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
	void child_1(char *argv[], char **envp,int *fd_list);
	void child_2(char *argv[], char **envp, int *fd_list);
	char *get_pathname(char *arg, char* paths);
	int create_probable_str(char **dest, char *arg, char *src, int i);
	int get_pathlocation(char **envp);
	void close_fds(int *fd_list, int *fd_in_out);
	void make_dups(int *new_stdin, int*new_stdout);
#endif