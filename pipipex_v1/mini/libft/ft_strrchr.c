/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:21:56 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/20 11:04:00 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int				ft_strlen1(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			*ft_strrchr(char *str, int c)
{
	int			i;
	char		*e;

	i = ft_strlen1(str);
	if (!(str))
		return (0);
	while (i > 0)
	{
		if (str[i] == c)
		{
			e = &str[i];
			return (e);
		}
		i--;
	}
	if (str[i] == c)
	{
		e = &str[i];
		return (e);
	}
	return (0);
}
