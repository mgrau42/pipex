/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:43:09 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 13:41:10 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	set_search(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		size;
	char	*strstart;
	char	*str;

	i = 0;
	if ((!s1) || (!set))
		return (NULL);
	while ((s1[i] != '\0') && (set_search(s1[i], set)))
		i++;
	if (i == (ft_strlen((char *)s1)))
		return (ft_strdup(""));
	strstart = (char *)&s1[i];
	i = ft_strlen(((char *)s1) - 1);
	if (i != -1)
		while ((i >= 0) && (set_search(s1[i], set)))
			i--;
	if ((!*s1) || (((char *)&s1[i]) == strstart))
		size = 2;
	else
		size = ((char *)&s1[i]) - strstart + 2;
	str = init_string(size);
	ft_strlcpy(str, strstart, size);
	return (str);
}

char	*init_string(int size)
{
	char	*str;

	str = (char *) malloc(sizeof (char) * size);
	if (!(str))
		exit (0);
	return (str);
}
