#include"pipex.h"
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include"../libft/libft.h"
#include<stddef.h>

char *Get_Pathname(char *arg, char**envp);
int charcount(char * str, char c);
int main (int argc, char *argv[], char **envp)
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
	p_id = fork();
	if (p_id == 0)
	{
		char *test[3];
		test[0] = Get_Pathname(argv[2], envp);
		test[1] = argv[1];
		test[2] = NULL;

		if (execve(test[0], test,envp) == -1)
		{
			perror(strerror(errno));
			return(-1);
		}
		return(1);
	}
	//hacer un fork
	// main se detiene mediante la funcion waitpid
	// child 1 ejecuta argv[2] invalid argument or succesfull exec
	// como introducir argv[1] como stdin
	// a la hora de pasar  salida final a argv[3] comprobar si puedo escribir en el
	printf("You are a cool %s, return fd = %i\n",argv[0],fd_list[0]);
	return(0);
}

char *Get_Pathname(char *arg, char**envp)
{
	int i;
	int pathlocation = 0;
	int numofstrings;
	char **pathlist;
	char *pathvarstr;
	char *tempstr;
	i = 0;
	//first lets check where the =Path is
	while((ft_strncmp("PATH=",envp[pathlocation],5)))
		pathlocation++;
	pathvarstr = strdup(envp[pathlocation] + 5);
	numofstrings = charcount(envp[pathlocation],':'); //we count the number of : which is equivalent to the number of possible paths
	pathlist = malloc(sizeof(char*) * (numofstrings)); // malloc de el numero de strings
	while (i < numofstrings)
	{
		while((strcmp()) // copiar hasta : y añadir a lista
	//	addtoliststr(pathlist,i,str);
		i++;
	}



	printf("this are the base files %s, %s, this is the possible number of paths: %i\n", arg, pathvarstr, numofstrings);
	return("/bin/cat");
}

int charcount(char *str, char c)
{
	int		i;
	int		count;
	
	count = 0;
	i = 0;
	if (!(str))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count += 1;
		i++;
	}
	if (str[i] == c)
		count += 1;
	return (count);
}

unsigned int	ft_strcharcpy(char *dest, char *src, char* size)
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