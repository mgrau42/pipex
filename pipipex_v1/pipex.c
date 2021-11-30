#include"pipex.h"
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include"../libft/libft.h"
#include<stddef.h>
#include <sys/wait.h>

char *get_pathname(char *arg, char* paths);
void init_c_argv(char *c_argv[],char *argv[],char *paths);
void child_1(char *argv[], char **envp);
unsigned int	ft_strcharcpy(char *dest, char *src, char until, unsigned int pos);
int create_probable_str(char **dest, char *arg, char *src, int i);
int get_pathlocation(char **envp);

int main (int argc, char *argv[], char **envp)
{
	int fd_list[3];										
	int p_id;

	if (!(num_of_args(argc, 5, 5))) 					//comprobamos el numero de argumentos
		return(error_exit(22));
	if ((fd_list[0] = open(argv[1],O_RDONLY)) == -1) 	// se abre el primer archivo
		return(error_exit(errno));

	if ((p_id = fork()) == 0) 							//hacemoss un fork, ahora hay dos procesos
		child_1(argv, envp);							//nos ocupamos del proceso hijo
	wait(0);
														// problema, si tengo error en el hijo como termino padre y viceversa
														// main se detiene mediante la funcion waitpid
														// child 1 ejecuta argv[2] invalid argument or succesfull exec
														// como introducir argv[1] como stdin
														// a la hora de pasar  salida final a argv[3] comprobar si puedo escribir en el
	return(0);
}

char *get_pathname(char *arg, char*paths)
{
	unsigned int i = 5;
	char *dest;

	dest = NULL;
	i = create_probable_str(&dest, arg, paths,i);
	while ((access(dest,X_OK)) == -1 && i < strlen(paths))
	{
		free(dest);
		i = create_probable_str(&dest, arg, paths,i);
	}
	printf("this is the current path" ANSI_RED "%s" ANSI_RESET "this is the pos %i original path" ANSI_CYAN "%s\n\n" ANSI_RESET,dest,i,(paths) + i);
	return(dest);
}

int get_pathlocation(char **envp)
{
	int i;
	i = 0;
	while((ft_strncmp("PATH=",envp[i],5))) // we got the start location of the portion we want
		i++;
	return(i);	
}

int create_probable_str(char **dest, char *arg, char *src, int i)
{
	*dest = malloc(sizeof(char) * ft_strlen((src + i)) + ft_strlen(arg) + 2);
	i = ft_strcharcpy(*dest,(src + i),':',0) + i; 
	ft_strcat(*dest,"/");
	ft_strcat(*dest,arg);
	printf("this is the current path" ANSI_RED "%s" ANSI_RESET "this is the pos %i original path" ANSI_CYAN "%s\n\n" ANSI_RESET,*dest,i,src + i);
	return(i);
}



unsigned int	ft_strcharcpy(char *dest, char *src, char until, unsigned int pos)
{
	unsigned int i;
	i = 0;
	if ((!dest) || (!src))
		return (0);
	while ((src[pos] != '\0' && src[pos] != until))
		dest[i++] = src[pos++];
	dest[i] = 0;
	return (++pos) ;
}


void init_c_argv(char *c_argv[],char *argv[],char *paths)
{
		c_argv[0] = get_pathname(argv[2], paths);
		c_argv[1] = argv[1];
		c_argv[2] = NULL;
}

void child_1(char *argv[], char **envp)
{
	char *c_argv[3];
	init_c_argv(c_argv, argv, envp[get_pathlocation(envp)]);
	if (execve(c_argv[0], c_argv,envp) == -1)
	{
		error_exit(errno);
		exit(0);
	}
}
