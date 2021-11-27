#include "mlx.h"
#include "fdf.h"
#include "get_next_line.h"
#include <stdlib.h>

void mlx_start(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "fdf");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
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
	fdf->pos_x = WIDTH / 2;
	fdf->pos_y = HEIGHT / 2;
}

int main(int ac, char **av)
{
	t_map map;
	t_mlx mlx;
	t_keys keys;
	t_fdf fdf;

	if (ac == 1)
		av[1] = ft_strdup("./maps/42.fdf");
	init(&map, &mlx, &keys, &fdf);
	/*if (ac != 2)*/
		/*return (error("\033[1;41mError arguments\033[0m"));*/
	map.map = parse_map(av[1]);
	if (!map.map)
		return (error("\033[1;41mError map\033[0m"));

	mlx_start(&mlx);

	mlx_hook(mlx.win, 17, 0, &cross_hook, &map);
	mlx_hook(mlx.win, 2, 0, &key_down_hook, &keys);
	mlx_hook(mlx.win, 3, 0, &key_up_hook, &keys);

	mlx_loop_hook(mlx.ptr, &draw, &fdf);

	free_split(map.map);
	mlx_loop(mlx.ptr);
}
