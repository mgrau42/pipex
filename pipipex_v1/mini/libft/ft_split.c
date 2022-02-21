/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:34:22 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/27 10:30:00 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		matrixl(char const *s, char c)
{
	int i;
	int len;

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

static int		strsplen(const char *s, char c, int i)
{
	int len;

	len = 0;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		len++;
		i++;
	}
	return (len);
}

static char		**bigfree(char **m, int e)
{
	while (e)
		free(m[e--]);
	free(m);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**matrix;
	int		i;
	int		e;
	int		g;

	if (!s)
		return (NULL);
	i = 0;
	e = 0;
	if (!(matrix = (char **)malloc((((matrixl(s, c)) + 1) * sizeof(char *)))))
		return (0);
	while ((s[i] != '\0') && (e < (matrixl(s, c))))
	{
		g = 0;
		while (s[i] == c)
			i++;
		if (!(matrix[e] = (char *)malloc(sizeof(char) * strsplen(s, c, i) + 1)))
			return (bigfree(matrix, e));
		while ((s[i] != '\0') && (s[i] != c))
			matrix[e][g++] = s[i++];
		matrix[e++][g] = '\0';
	}
	matrix[e] = 0;
	return (matrix);
}
