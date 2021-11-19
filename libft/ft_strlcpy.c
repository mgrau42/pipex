/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:12:32 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/09 13:18:03 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if ((!dest) || (!src))
		return (0);
	if (size != 0)
	{
		while ((i + 1 < (size)) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = 0;
		i = 0;
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
