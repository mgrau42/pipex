/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:07:53 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/20 11:02:46 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	*e;

	i = 0;
	if (!(str))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			e = &str[i];
			return (e);
		}
		i++;
	}
	if (str[i] == c)
	{
		e = &str[i];
		return (e);
	}
	return (0);
}
