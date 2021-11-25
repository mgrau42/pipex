#include"pipex.h"
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include"../libft/libft.h"
#include<stddef.h>

char *get_pathname(char *arg, char**envp);
void init_c_argv(char *c_argv[],char *argv[],char **envp);
void child_1(char *argv[], char **envp);
unsigned int	ft_strcharcpy(char *dest, char *src, char until, unsigned int pos);

int main (int argc, char *argv[], char **envp)
{
	int fd_list[3];
	int p_id;

	if (!(num_of_args(argc, 5, 5))) 					//comprobamos el numero de argumentos
		return(error_exit(22));
	if ((fd_list[0] = open(argv[1],O_RDONLY)) == -1) 	// se abre el primer archivo
		return(error_exit(errno));
	if ((p_id = fork()) == 0) 										//hacemoss un fork, ahora hay dos procesos
		child_1(argv, envp);						//nos ocupamos del proceso hijo
	wait(0);
// problema, si tengo error en el hijo como termino padre y viceversa
	// main se detiene mediante la funcion waitpid
	// child 1 ejecuta argv[2] invalid argument or succesfull exec
	// como introducir argv[1] como stdin
	// a la hora de pasar  salida final a argv[3] comprobar si puedo escribir en el
	return(0);
}

char *get_pathname(char *arg, char**envp)
{
	unsigned int i;
	int pathlocation = 0;
	char *pathvarstr;
	char *tempstr;
	//first lets check where the =Path is
	while((ft_strncmp("PATH=",envp[pathlocation],5)))
		pathlocation++;
	pathvarstr = ft_strdup(envp[pathlocation] + 5);
	tempstr = malloc(sizeof(char) * ft_strlen(pathvarstr) + 1);
	i = ft_strcharcpy(tempstr,pathvarstr,':',0);

 //we count the number of : which is equivalent to the number of possible paths
 // malloc de el numero de strings
	while()




	printf("this are the base files %s, %s,\n this is the current path %s, this is the pos %i\n", arg, pathvarstr,tempstr,i );
	return("/bin/cat");
}


unsigned int	ft_strcharcpy(char *dest, char *src, char until, unsigned int pos)
{
	unsigned int i;
	i = 0;
	if ((!dest) || (!src))
		return (0);
	while ((src[pos] != '\0' && src[pos] != until))
	{
		dest[i] = src[pos];
		++i;
		++pos;
	}
	dest[i] = 0;
	return (pos);
}


void init_c_argv(char *c_argv[],char *argv[],char **envp)
{
		c_argv[0] = get_pathname(argv[2], envp);
		c_argv[1] = argv[1];
		c_argv[2] = NULL;
}

void child_1(char *argv[], char **envp)
{
	char *c_argv[3];
	init_c_argv(c_argv, argv, envp);
	if (execve(c_argv[0], c_argv,envp) == -1)
	{
		error_exit(errno);
		exit(0);
	}
}
