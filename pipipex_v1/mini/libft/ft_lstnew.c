/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:30:55 by mgrau             #+#    #+#             */
/*   Updated: 2020/07/16 09:57:35 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newlst;

	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (!content)
		newlst->content = NULL;
	else
		newlst->content = content;
	newlst->next = NULL;
	return (newlst);
}
