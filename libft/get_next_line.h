#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef 	BUFFER_SIZE
#  define 	BUFFER_SIZE 32
#  endif
# define FD_SIZE 1024
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		val_ret (int fd, int num, char **str, char **line);
int		add_line (char **str, char **line);
int		get_next_line(int fd, char **line);
#endif