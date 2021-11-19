/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:19:35 by mgrau             #+#    #+#             */
/*   Updated: 2021/02/15 14:03:09 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_intdup(int *str1, int nsize)
{
	int		*ptr;
	int		i;

	i = 0;
	ptr = (int *)malloc(sizeof(int) * nsize);
	if (ptr == NULL)
		return (0);
	while (i < nsize)
	{
		ptr[i] = str1[i];
		i++;
	}
	return (ptr);
}
