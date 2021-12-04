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

void init(t_map *map, t_mlx *mlx, t_keys *keys, t_fdf *fdf, t_camera *camera)
{
	map->map = 0;
	map->width_map = 0;
	map->height_map = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->square_size = 0;
	
	mlx->ptr = 0;
	mlx->win = 0;
	mlx->img = 0;
	mlx->addr = 0;

	keys->esc = 0;
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
	keys->up = 0;
	keys->down = 0;
	keys->plus = 0;
	keys->minus = 0;
	keys->alpha_plus = 0;
	keys->alpha_minus = 0;
	keys->beta_plus = 0;
	keys->beta_minus = 0;
	keys->gamma_plus = 0;
	keys->gamma_minus = 0;
	keys->is_isometric = 0;
	keys->is_parralel = 0;
	keys->rotate = 0;
	keys->invert_color = 0;
	keys->shift = 0;
	keys->h = 0;
	keys->j = 0;
	keys->k = 0;
	keys->l = 0;
	keys->ctrl = 0;
	keys->mouse_zoom = 0;

	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_coefficient = 1;
	camera->offset_x = 0;
	camera->offset_y = 0;

	fdf->map = map;
	fdf->mlx = mlx;
	fdf->keys = keys;
	fdf->camera = camera;
	fdf->points = 0;
}

int main(int ac, char **av)
{
	t_map map;
	t_mlx mlx;
	t_keys keys;
	t_camera camera;
	t_fdf fdf;

	init(&map, &mlx, &keys, &fdf, &camera);
	if (ac != 2)
		return (error("\033[1;41mError arguments\033[0m"));
	map = parse_map(av[1]);
	if (!map.map)
		return (error("\033[1;41mError map\033[0m"));
	fdf.points = parse_points(&map);
	if (fdf.points == 0)
		return 0;

	mlx_start(&mlx);

	mlx_hook(mlx.win, 17, 0, &cross_hook, &map);
	mlx_hook(mlx.win, 2, 0, &key_down_hook, &keys);
	mlx_hook(mlx.win, 3, 0, &key_up_hook, &keys);
	mlx_hook(mlx.win, 4, 0, mouse_down_hook, &keys);
	mlx_hook(mlx.win, 5, 0, mouse_up_hook, &keys);

	mlx_loop_hook(mlx.ptr, &draw, &fdf);

	free_split(map.map);
	mlx_loop(mlx.ptr);
}
