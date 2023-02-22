/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:36:39 by mgrau             #+#    #+#             */
/*   Updated: 2023/02/22 12:04:50 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manu_utils.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/pipex.h"

/*
** This function takes in the number of arguments argc, the maximum allowed
** number of arguments maxargs, and the minimum allowed number of arguments minargs.
** It checks if argc is within the allowed range and returns 1 if it is, and 0 otherwise.
*/
int num_of_args(int argc, int maxargs, int minargs)
{
	// Check if argc is within the allowed range
	if ((argc > maxargs) || (argc < minargs))
		return (0);
	// Return 1 if argc is within the allowed range
	return (1);
}

/*
** This function prints an error message to standard error using the write system call.
** It takes in an error code, a string str to print before the command that caused the error,
** and the command cmd that caused the error. It returns the error code.
*/
int	error_message(int error, char *str, char *cmd)
{
	write(2, str, ft_strlen(str));
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 2);
	return (error);
}

/*
** This function frees the memory allocated for a matrix of strings.
** It takes in a pointer to the matrix matrix, and frees all the memory allocated for each string in the matrix using free().
** Finally, it frees the memory allocated for the matrix itself using free().
*/
void	free_matrix(char **matrix)
{
	int	i;

	// Free all memory allocated for the matrix
	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
