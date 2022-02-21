
#include "minishell.h"
#include <sys/wait.h>


void	launch_several_process(t_lst *node, int i)
{
	int		new_fd_list[2];
	int		*old_fd_list;

	old_fd_list = NULL;
	while (i > 0)
	{
		pipe(new_fd_list);
		g_ms->sh_pid = fork();
		if (g_ms->sh_pid == 0)  // we are in child
		{
			close(new_fd_list[0]);
			if (node->exe_state == SUCCESS)
				execute_child(node, new_fd_list, old_fd_list);
			else
				exit(0);
		}
		else			//we are in father
		{
//			ft_signal_main();
			handle_pipes(node,new_fd_list, old_fd_list);	//father_during_child_exec(node, new_fd_list, &old_fd_list);
//			close_all_fds();
		}
		node = node->next;
		i--;
	}
	wait_childs();
}

void	handle_pipes(t_lst *node, int new_pip[2], int old_pip[2]) // change old_pipe to fd list
{
	close(new_pip[1]);
	if (node->el_nbr != 1)
	{
		close((old_pip)[0]);
		free(old_pip);
	}
	if (node->el_nbr == g_ms->argc)
		close(new_pip[0]);
	else
		old_pip = copy_pipe(new_pip);
}

int	*copy_pipe(int pipe_in[2])
{
	int	*pipe_out;

	pipe_out = malloc(sizeof(int) * 2);
	pipe_out[0] = pipe_in[0];
	pipe_out[1] = pipe_in[1];
	return (pipe_out);
}

void	execute_child(t_lst *node, int new_fd_list[2], int old_fd_list[2])
{
	handle_defs(node->cmd);
	open_heredoc(node);
	if (node->el_nbr != 1)
		assing_fd(&node->file_in, old_fd_list[0], FD_IN); //fd_in is 0, we assing the pipe fd to our node
	if (node->el_nbr != g_ms->argc) // if element number is different from number of processes
		assing_fd(&node->file_out, new_fd_list[1], FD_OUT); //fd_is 1
	else					//if last process we simply close the out fd of the new pipe
		close(new_fd_list[1]);
	if (node->cmd[0])
	{
		if (is_builtin(node->cmd[0]))
		{
			dup_to_stdin_stdout(node->file_in, node->file_out);
			exec_builtin(node->cmd, 0); //0 means child
		}
		else
			call_execve(node);
	}
}

void	assing_fd(int *node_fd, int new_fd, int fd)
{
		if (*node_fd == fd)
			*node_fd = new_fd;
		else
			close(new_fd);
}

void	wait_childs(void)
{
	int		n_process;
	int		stat;
	pid_t	pid;

	n_process = g_ms->argc;
	while (n_process > 0)
	{
		pid = wait(&stat);
		if (pid == g_ms->sh_pid)
//			get_q_mark(stat);
		n_process--;
	}
}