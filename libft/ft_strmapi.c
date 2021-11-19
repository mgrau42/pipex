/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:13:46 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/15 11:08:01 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	char				*buff;
	unsigned int		i;

	i = 0;
	if ((!s) || (!f))
		return (NULL);
	if (!(str = (char *)malloc(ft_strlen((char *)s) + 1)))
		return (ft_strdup(""));
	buff = (char *)s;
	while (s[i] != '\0')
	{
		str[i] = f(i, buff[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
