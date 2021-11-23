#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>

char **malloc_bzero(size_t count)
{
	char** res;
	size_t i;

	i = 0;
	res = malloc(count);
	while (i < count / sizeof(char *))
		res[i++] = 0;
	return res;
}

int error(char *s)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	return (0);
}
