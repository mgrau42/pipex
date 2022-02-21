/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:38:39 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/06 13:39:13 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	a;
	unsigned int	i;
	char			*b;

	i = 0;
	a = c;
	b = (char*)str;
	while (i < n)
	{
		b[i] = a;
		i++;
	}
	return (b);
}
