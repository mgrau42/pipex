/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:22:12 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/20 11:44:22 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*array;
	int		i;

	i = 0;
	if ((num <= 0) || (size <= 0))
		return (ft_strdup(""));
	if (!(array = malloc(num * size)))
		return (ft_strdup(""));
	while (i < ((int)num * (int)size))
		((char*)array)[i++] = 0;
	return (array);
}
