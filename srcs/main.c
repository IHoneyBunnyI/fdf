#include "mlx.h"
#include "fdf.h"
#include <unistd.h>
#include "fcntl.h"

char** parse_map(char *map_path)
{
	char **map;
	int fd_map;

	fd_map = open(map_path, O_RDONLY);
	if (fd_map == -1)
		return (0);
	map = 0;
	return (map);
}

int error(char *s)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	return (0);
}

int main(int ac, char **av)
{
	char **map;
	t_mlx mlx;
	if (ac != 2)
		return (error("\033[1;41mError arguments\033[0m"));
	map = parse_map(av[1]);
	if (!map)
		return (error("\033[1;41mError map\033[0m"));
	mlx.mlx_ptr = mlx_init();
}
