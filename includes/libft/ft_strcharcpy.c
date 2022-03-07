/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:59:59 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 13:04:48 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strcharcpy(char *d, char *src, char u, unsigned int pos)
{
	unsigned int	i;

	i = 0;
	if ((!d) || (!src))
		return (0);
	while ((src[pos] != '\0' && src[pos] != u))
		d[i++] = src[pos++];
	d[i] = 0;
	return (++pos);
}
