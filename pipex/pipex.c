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
int child_1(char *argv[], char **envp);

int main (int argc, char *argv[], char **envp)
{
	int fd_list[3];
	int p_id;

	if (!(num_of_args(argc, 5, 5))) 					//comprobamos el numero de argumentos
		return(error_exit(22));
	if ((fd_list[0] = open(argv[1],O_RDONLY)) == -1) 	// se abre el primer archivo
		return(error_exit(errno));
	if ((p_id = fork()) == 0) 										//hacemoss un fork, ahora hay dos procesos
		return(child_1(argv, envp));						//nos ocupamos del proceso hijo
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
	int i;
	int pathlocation = 0;
	int numofstrings;
	char **pathlist;
	char *pathvarstr;
	///char *tempstr;
	i = 0;
	//first lets check where the =Path is
	while((ft_strncmp("PATH=",envp[pathlocation],5)))
		pathlocation++;
	pathvarstr = ft_strdup(envp[pathlocation] + 5);
	numofstrings = ft_charcount(envp[pathlocation],':'); //we count the number of : which is equivalent to the number of possible paths
	pathlist = malloc(sizeof(char*) * (numofstrings)); // malloc de el numero de strings
	while (i < numofstrings)
	{
//		while((strcmp()) // copiar hasta : y añadir a lista
	//	addtoliststr(pathlist,i,str);
		i++;
	}



	printf("this are the base files %s, %s, this is the possible number of paths: %i\n", arg, pathvarstr, numofstrings);
	return("/bin/cat");
}

/*
unsigned int	ft_strcharcpy(char *dest, char *src, char* until)
{
	unsigned int	i;

	i = 0;
	if ((!dest) || (!src))
		return (0);
	if (size != 0)
	{
		while ((i + 1 < (size)) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = 0;
		i = 0;
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
*/

void init_c_argv(char *c_argv[],char *argv[],char **envp)
{
		c_argv[0] = get_pathname(argv[2], envp);
		c_argv[1] = argv[1];
		c_argv[2] = NULL;
}

int child_1(char *argv[], char **envp)
{
	char *c_argv[3];
	init_c_argv(c_argv, argv, envp);
	if (execve(c_argv[0], c_argv,envp) == -1)
		return(error_exit(errno));
	return(0);
}
