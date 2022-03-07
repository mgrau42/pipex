/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:59:29 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 12:59:33 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strcat(char *dest, char *src)
{
	unsigned int		i;
	unsigned int		b;

	i = ft_strlen(dest);
	b = ft_strlen(src) + i;
	if (!(dest))
		return (b);
	while ((*src))
		dest[i++] = *src++;
	dest[i] = 0;
	return (b);
}
