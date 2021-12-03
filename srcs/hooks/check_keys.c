#include "fdf.h"

void check_keys(t_fdf *fdf, t_keys *keys)
{
	if (!keys->shift && keys->plus)
	{
		fdf->map->square_size += 1;
		fdf->camera->offset_y -= 10;
	}
	if (!keys->shift && keys->minus)
		if (fdf->map->square_size >= 2)
		{
			fdf->map->square_size -= 1;
			fdf->camera->offset_y += 10;
		}
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
	if (keys->rotate)
	{
		fdf->camera->alpha += 0.04;
		fdf->camera->beta += 0.04;
		fdf->camera->gamma += 0.04;
	}
	if (keys->invert_color)
	{
		t_point **points;
		points = fdf->points;
		for (int i = 0; i < fdf->map->height_map; i++)
		{
			for (int j = 0; j < fdf->map->width_map; j++)
			{
				if (points[i][j].color != 0xFFFFFF)
					points[i][j].color = 0xFFFFFF - points[i][j].color;
			}
		}
		keys->invert_color = 0;
	}
	if (keys->shift && keys->plus)
	{
		if (fdf->camera->z_coefficient < 10)
			fdf->camera->z_coefficient += 0.04;
	}
	if (keys->shift && keys->minus)
	{
		if (fdf->camera->z_coefficient > 0)
			fdf->camera->z_coefficient -= 0.04;
	}
}

