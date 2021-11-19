/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:31:07 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/23 09:45:21 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*cfound;
	unsigned char	d;
	unsigned char	*csrc;

	csrc = (unsigned char *)src;
	cfound = &d;
	d = c;
	i = 0;
	while (i < n)
	{
		if (csrc[i] == d)
		{
			cfound = &csrc[i];
			return (cfound);
		}
		i++;
	}
	return (0);
}
