#include"pipex.h"
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include"../libft/libft.h"
#include<stddef.h>


int main (int argc, char *argv[])
{
	int fd_list[3];
	int p_id;

	if (!(num_of_args(argc, 5, 5)))
	{
		write(1,"Invalid number of arguments\n",29);
		return(-1);
	}
	if ((fd_list[0] = open(argv[1],O_RDONLY)) == -1)
	{
		perror(strerror(errno));
		return(-1);
	}
	if ((p_id = fork()) == -1)
		return(-1);
	if (p_id == 0)
	{
		char *test[3];
		test[0] = argv[2];
		test[1] = argv[1];
		test[2] = NULL;
		write(1,"this is the child\n",19);
		execvp(argv[2], test);
		return(1);
	}
	else
		return(0);
	//hacer un fork
	// main se detiene mediante la funcion waitpid
	// child 1 ejecuta argv[2] invalid argument or succesfull exec
	// como introducir argv[1] como stdin
	// a la hora de pasar  salida final a argv[3] comprobar si puedo escribir en el
	printf("You are a cool %s, return fd = %i\n",argv[0],fd_list[0]);
}
