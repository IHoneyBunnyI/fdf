#include "mlx.h"
#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <stdio.h>

int lenth_file(char *map_path)
{
	char *line;
	int len_file;
	int fd_map;

	len_file = 0;
	line = 0;
	fd_map = 0;
	fd_map = open(map_path, O_RDONLY);
	if (fd_map == -1)
		return (ERROR);
	while (get_next_line(fd_map, &line))
	{
		len_file++;
		free(line);
	}
	free(line);
	close(fd_map);
	return (len_file);
}

void fill_map(char **map, int fd_map)
{
	char *line;
	int i;

	i = 0;
	line = 0;
	while (get_next_line(fd_map, &line))
	{
		map[i++] = ft_strdup(line);
		free(line);
	}
	free(line);
	close(fd_map);
}

int check_map(char **map, int len_file)
{
	int i;
	char **str_split_1;
	char **str_split_2;

	i = -1;
	while (++i < len_file)
	{
		str_split_1 = ft_split(map[i], ' ');
		str_split_2 = ft_split(map[2], ' ');
		if (size(str_split_1) != size(str_split_2))
				return ERROR;
	}
	return 0;
}

char** parse_map(char *map_path)
{
	char **map;
	int fd_map;
	int len_file;
	char *line;

	line = 0;
	len_file = lenth_file(map_path);
	if (len_file == ERROR)
		return 0;
	fd_map = open(map_path, O_RDONLY);
	map = malloc_bzero(sizeof(char *) * (len_file + 1));
	fill_map(map, fd_map);
	if (check_map(map, len_file) == ERROR)
		return 0;
	return (map);
}


void free_all(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(*(map + i));
		i++;
	}
	free(map);
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

	for (int j = 0; map[j]; j++)
		printf("%d) %s\n", j, map[j]);

	free_all(map);
	(void)mlx;
	/*mlx.mlx_ptr = mlx_init();*/
	/*while (1) ;*/
}
