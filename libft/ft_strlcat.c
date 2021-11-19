/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:10:55 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/20 12:41:37 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		b;

	i = ft_strlen(dest);
	b = ft_strlen(src) + i;
	if (i > size)
		return (b = b + size - i);
	while ((*src) && (i + 1) < size)
		dest[i++] = *src++;
	dest[i] = 0;
	return (b);
}
