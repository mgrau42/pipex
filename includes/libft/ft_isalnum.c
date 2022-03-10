/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:24:11 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/10 12:53:30 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (((c < 65) || (c > 90)) && ((c < 97) || \
	(c > 122)) && ((c < 48) || (c > 57)))
		return (0);
	return (1);
}
