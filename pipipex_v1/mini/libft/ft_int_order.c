/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:45:25 by mgrau             #+#    #+#             */
/*   Updated: 2021/02/15 13:55:47 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft.h"

void	ft_int_order(int *order, int *var, int size)
{
	int i;
	int y;
	int j;

	y = 0;
	while (y < size)
	{
		i = y + 1;
		while (i < size)
		{
			if (var[y] < var[i])
			{
				j = order[y];
				order[y] = order[i];
				order[i] = j;
				j = var[y];
				var[y] = var[i];
				var[i] = j;
			}
			i++;
		}
		y++;
	}
}
