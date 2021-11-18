#include "manu_utils.h"

bool num_of_args (int argc,int maxargs, int minargs)
{
	if ((argc > maxargs) || (argc < minargs))
		return(False);
	return(True);
}