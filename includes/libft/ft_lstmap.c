/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:29:43 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 12:50:41 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstclearm(t_list **t, void (*d)(void *))
{
	t_list	*tmp;

	if (!d)
		return (NULL);
	while (*t != '\0')
	{
		d((*t)->content);
		tmp = *t;
		*t = tmp->next;
		free(tmp);
	}
	*t = 0;
	return (NULL);
}

t_list	*ft_lstmap(t_list *t, void *(*f)(void *), void (*d)(void *))
{
	t_list	*newelem;

	if (t == NULL || f == NULL)
		return (NULL);
	newelem = (t_list *)malloc(sizeof(t_list));
	if (!newelem)
		return (ft_lstclearm(&newelem, d));
	newelem->content = f(t->content);
	if (t->next)
	{
		newelem->next = ft_lstmap(t->next, f, d);
		if (newelem->next == NULL)
			return (ft_lstclearm(&newelem, d));
	}
	else
		newelem->next = NULL;
	return (newelem);
}
