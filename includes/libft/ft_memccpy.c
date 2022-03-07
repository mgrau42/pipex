/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:29:48 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/06 13:30:30 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*cfound;
	unsigned char	d;
	unsigned char	*csrc;
	unsigned char	*cdest;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	cfound = &d;
	d = c;
	i = 0;
	while (i < n)
	{
		if (csrc[i] == d)
		{
			cdest[i] = csrc[i];
			i++;
			cfound = &cdest[i];
			return (cfound);
		}
		cdest[i] = csrc[i];
		i++;
	}
	return (0);
}
