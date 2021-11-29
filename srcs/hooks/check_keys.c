#include "fdf.h"

void check_keys(t_fdf *fdf, t_keys *keys)
{
	if (keys->plus)
		fdf->map->square_size += 1;
	if (keys->minus)
		if (fdf->map->square_size > 2)
			fdf->map->square_size -= 1;

	if (keys->a)
			fdf->map->offset_x -= 3;
	if (keys->d)
			fdf->map->offset_x += 3;
	if (keys->w)
			fdf->map->offset_y -= 3;
	if (keys->s)
		fdf->map->offset_y += 3;

	if (keys->up)
		fdf->camera->alpha += 0.05;
	if (keys->down)
		fdf->camera->alpha -= 0.05;
	if (keys->right)
		fdf->camera->beta += 0.05;
	if (keys->left)
		fdf->camera->beta -= 0.05;
}

