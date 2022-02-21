#include "libft.h"
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*str[FD_SIZE];					/* Se declara una variable estatica que contendra un puntero a cada copia de los textos de cada fd*/
	char			*temp;
	int				num;

	if (!(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))		/* Se asigna la memoria al buffer tneiendo en cuenta el espacio para el caracter nulo del final*/
		return (-1);
	if ((fd < 0) || BUFFER_SIZE < 0 || !(line) || read(fd, buffer, 0) < 0)	/* Se realiza una comprobacion de errores*/
		return (-1);
	while ((num = read(fd, buffer, BUFFER_SIZE)) > 0)			/* Se lee BUFFER_SIZE bytes del archivo asociado al fd guradandolo en el buffer y se guarda el numero de bytes leidos en num , hasta el EOF*/
	{
		buffer[num] = '\0';						/* Se añade el nulo al final de la cadena*/
		if (str[fd] == NULL)						/* En caso de ser nulo se pasa una copia del primer buffer leido usando dicha fd*/
			str[fd] = ft_strdup(buffer);
		else								/* En caso contrario se expande la cadena asegurandose de liberar la memoria ya no utilizada*/
		{
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))					/*Para ir linea a linea, en caso de encontrar un salto de linea dentro de nuestra cadena guardada salimos de nuestro while*/
			break ;
	}
	free(buffer);								/*Liberamos la memoria*/
	return (val_ret(fd, num, str, line));					/*Se usa la funcion val_ret que determina el valor a devolver de nuestra funcion*/
}

int		add_line(char **s, char **line)
{
	int		len;
	char	*aux;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')				/* Contamos los caracteres hasta el salto de linea o hhasta el final de la cadena*/
		len++;
	if ((*s)[len] == '\n')							/* Si se trata de un salto de linea*/
	{
		*line = ft_substr(*s, 0, len);					/* Guardamos una copia de la cadena hasta el salto de linea en line*/
		aux = ft_strdup(&((*s)[len + 1]));				/* Hacemos lo mismo liberando memoria para guardar la linea en nuestra variable estatica*/
		free(*s);
		*s = aux;
	}
	else if ((*s)[len] == '\0')						/* En caso e tratarse de un nulo, es decier, el EOF simplemente guardamos la copia liberamos memoria y devolvemos 0*/
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);								/*En caso de haber guardado una linea sin llegar al EOF*/
}

int		val_ret(int fd, int num, char **str, char **line)
{
	if (num < 0)								/*En caso de error al leer se devuelve -1*/
		return (-1);
	else if ((num == 0) && (str[fd] == NULL))				/*En caso de tratarse del EOF se de vuelve un 0*/
	{
		*line = ft_strdup("");						/*Al ser un EOF la linea devuelta en este caso es nula*/
		free(*str);							/*Se libera la memoria asignada a str*/
		*str = NULL;
		return (0);
	}
	else
		return (add_line(&str[fd], line));				/* En caso de haberse leido una linea usamos la funcion add line para guardar nuestra lininea en  la variable line*/
}
