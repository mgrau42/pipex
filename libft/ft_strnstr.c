/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:16:20 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/09 11:16:28 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, unsigned int len)
{
	unsigned int		i;
	int					y;
	char				*ret;

	i = 0;
	y = 0;
	ret = to_find;
	if (to_find[0] == 0)
		return (str);
	while ((str[i] != 0) && (i < len))
	{
		if (str[i] == to_find[y])
		{
			while (str[i + y] == to_find[y])
			{
				if ((y++ + i) > len)
					return (0);
				if (to_find[y] == 0)
					return ((ret = &str[i]));
			}
			y = 0;
		}
		i++;
	}
	return (0);
}
