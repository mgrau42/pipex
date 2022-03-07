/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:08:38 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 13:44:12 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	lennum(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char				*str;
	unsigned int		len;
	unsigned int		nb;
	unsigned int		i;

	nb = which_num(n);
	len = lennum(nb);
	i = 0;
	str = init_str(n, len);
	if (n < 0)
	{
		str[i] = '-';
		len++;
	}
	i = len - 1;
	while (nb >= 10)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	str[i] = nb % 10 + '0';
	str[len] = '\0';
	return (str);
}

char	*init_str(int n, unsigned int len)
{
	char	*str;

	if (n < 0)
		str = (char *) malloc(sizeof (char) * len + 1 + 1);
	else
		str = (char *) malloc(sizeof (char) * len + 1);
	if (!(str))
		exit (0);
	return (str);
}

int	which_num(int n)
{
	int	nb;

	nb = n;
	if (n < 0)
		nb = -n;
	return (nb);
}
