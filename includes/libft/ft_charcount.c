/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:38:16 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 12:27:56 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_charcount(char *str, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!(str))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count += 1;
		i++;
	}
	if (str[i] == c)
		count += 1;
	return (count);
}
