
#include"pipex.h"

char *get_pathname(char *arg, char*paths)
{
	unsigned int i = 5;
	char *dest;

	if (access(arg,X_OK) != -1)
		return(arg);
	dest = NULL;
	i = create_probable_str(&dest, arg, paths,i);
	while ((access(dest,X_OK)) == -1)
	{
		if (i >= strlen(paths) - 5)
		{
			free(dest);
			error_message(errno,"command not found ",arg);
			return(NULL);
		}
		free(dest);
		i = create_probable_str(&dest, arg, paths,i);
	}
	return(dest);
}

char *get_pathlocation(char **envp)
{
	int i;
	i = 0;
	while((ft_strncmp("PATH=",envp[i],5))) // we got the start location of the portion we want
		i++;
	return(envp[i]);	
}

int create_probable_str(char **dest, char *arg, char *src, int i)
{
	*dest = malloc(sizeof(char) * ft_strlen((src + i)) + ft_strlen(arg) + 2);
	i = ft_strcharcpy(*dest,(src + i),':',0) + i; 
	ft_strcat(*dest,"/");
	ft_strcat(*dest,arg);
	return(i);
}
