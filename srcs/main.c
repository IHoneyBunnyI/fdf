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
		free_split(str_split_1);
		free_split(str_split_2);
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

void free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(*(split + i));
		i++;
	}
	free(split);
}

void mlx_start(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "fdf");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->ptr, &mlx->bpp, &mlx->size_line, &mlx->endian);
}

void init(t_map *map, t_mlx *mlx, t_keys *keys, t_fdf *fdf)
{
	keys->esc = 0;
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
	keys->up = 0;
	keys->down = 0;
	fdf->map = map;
	fdf->mlx = mlx;
	fdf->keys = keys;
	fdf->pos_x = WIDTH / 2 - W_RECT;
	fdf->pos_y = HEIGHT / 2 - W_RECT;
}

int main(int ac, char **av)
{
	t_map map;
	t_mlx mlx;
	t_keys keys;
	t_fdf fdf;

	init(&map, &mlx, &keys, &fdf);
	if (ac != 2)
		return (error("\033[1;41mError arguments\033[0m"));
	map.map = parse_map(av[1]);
	if (!map.map)
		return (error("\033[1;41mError map\033[0m"));

	mlx_start(&mlx);

	/*mlx_hook(mlx.win, 17, 0, &cross_hook, &map);*/
	/*mlx_hook(mlx.win, 2, 0, &key_down_hook, &keys);*/
	/*mlx_hook(mlx.win, 3, 0, &key_up_hook, &keys);*/

	/*mlx_loop_hook(mlx.ptr, &draw, &fdf);*/

	draw(&fdf, &mlx);
	/*free_split(map.map);*/
	mlx_loop(mlx.ptr);
}
