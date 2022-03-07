/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:36:39 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 14:17:23 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manu_utils.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/pipex.h"

int	num_of_args(int argc, int maxargs, int minargs)
{
	if ((argc > maxargs) || (argc < minargs))
		return (0);
	return (1);
}

int	error_message(int error, char *str, char *cmd)
{
	write(2, str, ft_strlen(str));
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 2);
	return (error);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
