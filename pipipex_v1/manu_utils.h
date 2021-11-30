#ifndef MANU_UTILS_H
# define MANU_UTILS_H
#  ifndef _BOOL
    typedef unsigned char bool;
	static const bool False = 0;
	static const bool True = 1;
#  endif
	bool num_of_args (int argc,int maxargs, int minargs);
	int error_exit(int error);

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