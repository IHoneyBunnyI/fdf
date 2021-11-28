#include "fdf.h"

int is_num_or_minus(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	if (c == '-')
		return 1;
	return 0;
}
