/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:00:46 by mgrau             #+#    #+#             */
/*   Updated: 2023/02/22 12:27:00 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/pipex.h"

// Function: get_pathname
// Returns the full path of the executable file
// If the file can be executed in the current directory, it returns the path of the file
// If not, it checks the directories in PATH environment variable to find the file

char *get_pathname(char *arg, char* paths)
{
    unsigned int i;
    char *dest;
    
    // If the file can be executed in the current directory, return the file path
    if (access(arg, X_OK) != -1)
        return (arg);
    
    // Search in PATH directories
    dest = NULL;
    i = create_probable_str(&dest, arg, paths, 5);
    while ((access(dest, X_OK)) == -1)
    {
        if (i >= strlen(paths) - 5)
        {
            // File not found in PATH directories
            free(dest);
            error_message(errno, "command not found ", arg);
            return (NULL);
        }
        free(dest);
        i = create_probable_str(&dest, arg, paths, i);
    }
    return (dest);
}


// Function: get_pathlocation
// Returns the PATH environment variable value from envp array
char *get_pathlocation(char **envp)
{
    int i;
    
    // Search for PATH in envp array
    i = 0;
    while ((ft_strncmp("PATH=", envp[i], 5)))
        i++;
    return (envp[i]);
}


// Function: create_probable_str
// Helper function to create path with possible locations of the executable
int create_probable_str(char **dest, char *arg, char *src, int i)
{
    // Allocate memory for destination string
    *dest = malloc(sizeof(char) * ft_strlen((src + i)) + ft_strlen(arg) + 2);
    
    // Copy the directory path from PATH environment variable to destination
    i = ft_strcharcpy(*dest, (src + i), ':', 0) + i;
    
    // Concatenate the executable name to the path
    ft_strcat(*dest, "/");
    ft_strcat(*dest, arg);
    return (i);
}
