#include "fdf.h"

void check_keys(t_fdf *fdf, t_keys *keys)
{
	if (keys->plus)
		fdf->map->square_size += 1;
	if (keys->minus)
		if (fdf->map->square_size > 2)
			fdf->map->square_size -= 1;

	if (keys->a)
		if (fdf->map->offset_x > 1)
			fdf->map->offset_x -= 3;
	if (keys->d)
			fdf->map->offset_x += 3;
	if (keys->w)
		if (fdf->map->offset_y > 0)
			fdf->map->offset_y -= 3;
	if (keys->s)
		fdf->map->offset_y += 3;
	if (keys->right)
	{
		fdf->map->angle_x += 0.015;
	}
	if (keys->left)
	{
		fdf->map->angle_x -= 0.015;
	}
	if (keys->up)
		fdf->map->angle_y -= 0.015;
	if (keys->down)
		fdf->map->angle_y += 0.015;


	if (keys->up)
		fdf->camera->alpha += 0.05;
	if (keys->down)
		fdf->camera->alpha -= 0.05;
}

