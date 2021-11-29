#include "fdf.h"

void check_keys(t_fdf *fdf, t_keys *keys)
{
	if (keys->plus)
		fdf->map->square_size += 1;
	if (keys->minus)
		if (fdf->map->square_size > 2)
			fdf->map->square_size -= 1;
	if (keys->a || keys->left)
			fdf->camera->offset_x -= 3;
	if (keys->d || keys->right)
			fdf->camera->offset_x += 3;
	if (keys->w || keys->up)
			fdf->camera->offset_y -= 3;
	if (keys->s || keys->down)
			fdf->camera->offset_y += 3;
	if (keys->alpha_plus)
		fdf->camera->alpha += 0.05;
	if (keys->alpha_minus)
		fdf->camera->alpha -= 0.05;
	if (keys->beta_plus)
		fdf->camera->beta += 0.05;
	if (keys->beta_minus)
		fdf->camera->beta -= 0.05;
	if (keys->gamma_plus)
		fdf->camera->gamma += 0.05;
	if (keys->gamma_minus)
		fdf->camera->gamma -= 0.05;
}

