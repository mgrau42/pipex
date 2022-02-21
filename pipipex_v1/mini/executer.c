

#include "minishell.h"
#include <fcntl.h>


void	start_executer(void)
{
	int		i;
	t_lst	*node;

	g_ms->state = EXECUTING;
	i = g_ms->prcs_n; //is our argc equivalent to number of processes?
	node = g_ms->instr; //is this the start of our node linked list
	if (i == 1) //depending on the number of processes to execute we need to handle this differently
		launch_single_process(node);
	else
		launch_several_process(node, i);
	g_ms->sh_pid = 0;
	g_ms->state = READING;
}

//where is our equivalent to node->cmd? the list containing argumensts such as [KEY=VALUE,ls,wc]
void	launch_single_process(t_lst *node)
{
	if (node->exe_state == SUCCESS)
	{
		handle_defs(node->cmd); //
		open_heredoc(node);
		if (node->cmd[0])
		{
			if (is_builtin(node->cmd[0]))
				launch_from_father(node);
			else
				launch_from_fork(node);
		}
	}
}

int	is_builtin(char *arg)
{
	if (precise_cmp(arg, "pwd", 3))
		return (1);
	else if (precise_cmp(arg,"cd", 2))
		return (1);
	else if (precise_cmp(arg, "echo", 4))
		return (1);
	else if (precise_cmp(arg, "env", 3))
		return (1);
	else if (precise_cmp(arg, "export", 6))
		return (1);
	else if (precise_cmp(arg,"unset", 5))
		return (1);
	else if (precise_cmp(arg, "exit", 4))
		return (1);
	else
		return (0);
}

int precise_cmp(char *s1,char *s2, int size)
{
	if (ft_strlen(s1) == size && ft_strlen(s2) == size && !ft_strncmp(s1, s2, size))
		return (1);
	return(0);
}

//hdoc_name not yet set

void	open_heredoc(t_lst *node)
{
	char	*path;

	path = NULL;
	if (!node->herename) // herename location where our heredoc name is stored
		return ;
	else
	{
		path = ft_strjoin(TMP_PATH, node->herename);
		node->file_in = open(path, O_RDONLY);
		free(path);
	}
}

void	launch_from_father(t_lst *node)
{
	int		stdin_fd;
	int		stdout_fd;

	stdin_fd = dup(0);
	stdout_fd = dup(1); // duplicados de nuestros std in y outs para restaurarlos
	dup_to_stdin_stdout(node->file_in, node->file_out); //asignamos las salidas paara este proceso
	exec_builtin(node->cmd, 1); //1 means father
	dup_to_stdin_stdout(stdin_fd, stdout_fd); //se restauran
}

void	dup_to_stdin_stdout(int fd_in, int fd_out)
{
	if (fd_in != 0)
	{
		if (dup2(fd_in, 0) == -1)
			printf("error in dup2");//error_message();
		close(fd_in);
	}
	if (fd_out != 1)
	{
		if (dup2(fd_out, 1) == -1)
			printf("error in dup2");//error_message();
		close(fd_out);
	}
}

void	exec_builtin(char **arg, int type)
{
	/*if (precise_cmp(arg[0], "pwd", 3))
		ft_pwd();
	else if (precise_cmp(arg[0],"cd", 2))
		ft_cd();
	else if (precise_cmp(arg[0], "echo", 4))
		ft_echo();
	else if (precise_cmp(arg[0], "env", 3))
		ft_env();
	else if (precise_cmp(arg[0], "export", 6))
		ft_export();
	else if (precise_cmp(arg[0],"unset", 5))
		ft_unset();
	else if (precise_cmp(arg[0], "exit", 4))
		ft_exit();
	if (type == 0) //0 means child
		exit (0);*/
}

void	launch_from_fork(t_lst *node)
{
	//g_ms->state = EXECUTING; should be already working
	g_ms->sh_pid = fork();
	if (g_ms->sh_pid == 0)
		call_execve(node);
	else
	{
//		ft_signal_main();
//		close_all_fds(node);
		wait_childs();
		g_ms->state = READING;
	}
}

void	call_execve(t_lst *node)
{
	char	*path;
	char	**env;

//	ft_signal_main();
	dup_to_stdin_stdout(node->file_in, node->file_out);
//	path = find_exec_path(node->cmd);
//	env = clone_environment(g_ms->sh_env, FALSE);
	if (execve(path, node->cmd, env) == -1)
//		error_message();
}

///*************////