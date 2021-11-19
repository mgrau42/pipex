/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:18:46 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/15 11:39:42 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int i;
	int neg;
	int nb;

	nb = 0;
	i = 0;
	neg = 1;
	while ((str[i] == ' ') || (str[i] == '\t')\
	|| (str[i] == '\n') || (str[i] == '\v') ||\
	(str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
	{
		neg = neg * -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
		nb = (nb * 10) + (str[i++] - 48);
	return (nb * neg);
}
