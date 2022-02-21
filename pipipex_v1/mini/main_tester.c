
#include "minishell.h"
void init_g_struct(t_lst	*first);
void free_struct(int argc,t_lst *struc);

int main(int argc, char *argv[], char **envp)
{
	t_lst	*first;
	first = malloc(sizeof(t_lst *));
	g_ms = malloc(sizeof(t_ms*));
	g_ms->instr = first;
	g_ms->prcs_n = 1;
	printf("hi, this is the tester for the execution part of the manushell!!! \n\n");
	printf("first off lets initialize  our structure\n");
	printf("wont be using %i, or %s\n", argc, argv[0]);
	init_g_struct(first);
	printf("%s\n",envp[0]);
	//free_struct(argc,g_ms->instr);

}

/*	int				el_nbr;
	int				file_in;
	int				file_out;
	int				exe_state;
	size_t			ln;
	struct s_lst	*next;*/
void init_g_struct(t_lst	*first)
{
	t_lst *tmp;

	tmp = first;
	int i;
	i = 0;
	tmp->cmd = malloc(sizeof(char *) * 4);
	tmp->cmd[0] = "thing=this";
	tmp->cmd[1] = NULL;
	tmp->cmd[2] = NULL;
	tmp->cmd[3] = NULL;
	tmp->el_nbr = i;
	tmp->file_in = 0;
	tmp->file_out = 1;
	tmp->exe_state = READING;

}

void free_struct(int argc,t_lst *struc)
{
	t_lst *tmp;
	int i;
	i = 0;

	while(i < argc)
	{
		tmp = struc->next;
		free(struc);
		struc = tmp;
	}
	free(struc);

}