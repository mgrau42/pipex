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

void error_exit(int error, char *str, char *cmd, int status)
{
	write(1,str,ft_strlen(str));
	write(1, strerror(error), ft_strlen(strerror(error)));
	write(1,"\n",1);
	putstderror(str, cmd);
    exit(status);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void putstderror(char *message, char *cmd)
{		
	write(2,message,ft_strlen(message));
	write(2,cmd,ft_strlen(cmd));
	write(2,"\n",2);
}

//str for open:"open filename: %s\n"
//str for dup: "dup2: filename -> stdin: %s\n" or "dup2: %s -> stdout: %s\n"
//str for close: "close filename: %s\n"