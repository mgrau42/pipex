#ifndef MANU_UTILS_H
# define MANU_UTILS_H
#  ifndef _BOOL
    typedef unsigned char bool;
	static const bool False = 0;
	static const bool True = 1;
#  endif
	bool num_of_args (int argc,int maxargs, int minargs);
	int error_exit(int error);
#endif