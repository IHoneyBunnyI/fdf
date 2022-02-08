#include "mlx.h"
#include "fdf.h"

t_map	*init_map(t_map *map)
{
	map->map = 0;
	map->width_map = 0;
	map->height_map = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->square_size = 0;
	return (map);
}

t_mlx	*init_mlx(t_mlx *mlx)
{
	mlx->ptr = 0;
	mlx->win = 0;
	mlx->img = 0;
	mlx->addr = 0;
	return (mlx);
}

void intit_keys_second(t_keys *keys)
{
	keys->h = 0;
	keys->j = 0;
	keys->k = 0;
	keys->l = 0;
	keys->ctrl = 0;
	keys->mouse_zoom = 0;
	keys->left_mouse = 0;
	keys->right_mouse = 0;
	keys->wheel = 0;
}

t_keys	*init_keys(t_keys *keys)
{
	intit_keys_second(keys);
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
	keys->gamma_rotate = 0;
	keys->invert_color = 0;
	keys->shift = 0;
	return (keys);
}

t_camera	*init_camera(t_camera *camera)
{
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_coefficient = 1;
	camera->offset_x = 0;
	camera->offset_y = 0;
	camera->speed_rotate = 0;
	camera->acceleration = 1;
	return (camera);
}
