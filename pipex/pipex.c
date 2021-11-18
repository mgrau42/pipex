#include"pipex.h"
#include<unistd.h>

int main (int argc, char *argv)
{
	if (!(num_of_args(argc, 5, 5)))
	{
		write(1,"Invalid number of arguments\n",29);
		return(-1);
	}
	write(1,"You are a cool poppa\n",22);
}
