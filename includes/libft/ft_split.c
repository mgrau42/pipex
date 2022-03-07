/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:34:22 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 13:42:16 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	matrixl(char const *s, char c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			i = 0;
		else if (i == 0)
		{
			i = 1;
			len++;
		}
		s++;
	}
	return (len);
}

static int	strsplen(const char *s, char c, int i)
{
	int	len;

	len = 0;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		len++;
		i++;
	}
	return (len);
}

static char	**bigfree(char **m, int e)
{
	while (e)
		free(m[e--]);
	free(m);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		i;
	int		e;
	int		g;

	if (!s)
		return (NULL);
	i = 0;
	e = 0;
	matrix = init_matrix(s, c);
	while ((s[i] != '\0') && (e < (matrixl(s, c))))
	{
		g = 0;
		while (s[i] == c)
			i++;
		matrix[e] = (char *)malloc(sizeof(char) * strsplen(s, c, i) + 1);
		if (!(matrix[e]))
			return (bigfree(matrix, e));
		while ((s[i] != '\0') && (s[i] != c))
			matrix[e][g++] = s[i++];
		matrix[e++][g] = '\0';
	}
	matrix[e] = 0;
	return (matrix);
}

char	**init_matrix(char const *s, char c)
{
	char	**matrix;

	matrix = (char **)malloc((((matrixl(s, c)) + 1) * sizeof(char *)));
	if (!(matrix))
		exit (0);
	return (matrix);
}
