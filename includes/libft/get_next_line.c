/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:22:45 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 13:28:34 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			*bf;
	static char		*str[FD_SIZE];
	char			*temp;
	int				num;

	bf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!(bf) || (fd < 0) || BUFFER_SIZE < 0 || !(line) || read(fd, bf, 0) < 0)
		return (-1);
	num = read(fd, bf, BUFFER_SIZE);
	while (num > 0)
	{
		bf[num] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(bf);
		else
		{
			temp = ft_strjoin(str[fd], bf);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	free(bf);
	return (val_ret(fd, num, str, line));
}

int	add_line(char **s, char **line)
{
	int		len;
	char	*aux;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		aux = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = aux;
	}
	else if ((*s)[len] == '\0')
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

int	val_ret(int fd, int num, char **str, char **line)
{
	if (num < 0)
		return (-1);
	else if ((num == 0) && (str[fd] == NULL))
	{
		*line = ft_strdup("");
		free(*str);
		*str = NULL;
		return (0);
	}
	else
		return (add_line(&str[fd], line));
}
