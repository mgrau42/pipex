/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:32:31 by mgrau             #+#    #+#             */
/*   Updated: 2023/02/22 12:35:29 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/pipex.h"

/* Function to tokenize the input command 
** The ft_tokargs function takes in the command line arguments as input
** and tokenizes them into individual commands, creating a linked list of commands
** and returning a pointer to the head of the list. 
** The function iterates over the input arguments starting from the third element and creates
** a new command node for each argument. It then links each command node
** to the next node and returns a pointer to the head node.
*/
t_cmd	*ft_tokargs(int argc, char *argv[])
{
	int		i;
	t_cmd	*cmd;
	t_cmd	*tmp;

	i = 2;
	cmd = new_cmd(argv[i++]);
	tmp = cmd;
	while (i < argc - 1)
	{
		tmp->nextcmd = new_cmd(argv[i]);
		tmp = tmp->nextcmd;
		if (!tmp)
		{
			del_cmd_lst(cmd);
			exit(error_message(errno, "Allocation error: ", "cmd_lst"));
		}
		i++;
	}
	return (cmd);
}

/* Function to delete a linked list of commands 
** The del_cmd_lst function takes in a pointer to the head of the command linked list
** and deletes each node in the list. It does this by iterating over the linked list
** and freeing the memory allocated for each command node. It also calls the close_fds
** function to close any open file descriptors associated with each node.
*/
void	del_cmd_lst(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd->nextcmd;
		close_fds(cmd->fd_list, NULL);
		free_matrix(cmd->argv);
		free(cmd);
		cmd = tmp;
	}
}

/* Function to create a new command node 
** The new_cmd function creates a new command node and returns a pointer to the node.
** The function takes in a string containing the command and tokenizes it into an array of strings 
** representing the command's arguments. It allocates memory for the new command node, sets the node's 
** argument count and file descriptor list to default values, and links the node to the previous node in 
** the command linked list.
*/
t_cmd	*new_cmd(char *cmd)
{
	t_cmd	*new;

	if (!cmd)
		return (NULL);
	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!(new))
		return (NULL);
	new->argv = ft_split(cmd, ' ');
	new->argc = ft_strlen((void *)new->argv);
	new->fd_list[0] = -1;
	new->fd_list[1] = -1;
	new->prev = NULL;
	new->nextcmd = NULL;
	return (new);
}
