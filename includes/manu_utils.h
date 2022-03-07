/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manu_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:48:28 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 12:00:03 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANU_UTILS_H
# define MANU_UTILS_H

int		num_of_args(int argc, int maxargs, int minargs);
int		error_message(int error, char *str, char *cmd);
void	free_matrix(char **matrix);

/*
** system color definition
*/
# define ANSI_RED     "\x1b[31m"
# define ANSI_GREEN   "\x1b[32m"
# define ANSI_YELLOW  "\x1b[33m"
# define ANSI_BLUE    "\x1b[34m"
# define ANSI_MAGENTA "\x1b[35m"
# define ANSI_CYAN    "\x1b[36m"
# define ANSI_RESET   "\x1b[0m"
#endif