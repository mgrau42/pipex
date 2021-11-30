/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:36:39 by mgrau             #+#    #+#             */
/*   Updated: 2021/11/24 13:45:43 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manu_utils.h"
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

bool num_of_args (int argc,int maxargs, int minargs)
{
	if ((argc > maxargs) || (argc < minargs))
		return(False);
	return(True);
}

int error_exit(int error)
{
	write(1,strerror(error),ft_strlen(strerror(error)));
	return(-1);
}