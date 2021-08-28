#include "fdf.h"

int error(char *s)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (error("\033[1;41mError arguments\033[0m"));
	(void)av;
	void *ptr = mlx_init();
	(void)ptr;
}
