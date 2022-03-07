/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstrncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:41:40 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 12:52:37 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_revstrncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	m;

	i = 0;
	y = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[y] != '\0')
		y++;
	m = (--i) - n;
	n = (--y) - n;
	while ((i > m) || (y > n))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[y])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[y]);
		}
		i--;
		y--;
	}
	return (0);
}
