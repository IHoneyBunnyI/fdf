#include "fdf.h"

static void	R(t_fdf *fdf, t_keys *keys)
{
	if (keys->rotate)
	{
		if (fdf->camera->speed_rotate < 1.0 && fdf->camera->acceleration == 1)
			fdf->camera->speed_rotate += 0.002;
		if (fdf->camera->speed_rotate > 1 || fdf->camera->acceleration == -1)
		{
			fdf->camera->acceleration = -1;
			fdf->camera->speed_rotate -= 0.001;
			if (fdf->camera->speed_rotate < -1)
				fdf->camera->acceleration = 1;
		}
		fdf->camera->alpha += 0.04 * fdf->camera->speed_rotate;
		fdf->camera->beta += 0.04 * fdf->camera->speed_rotate;
		fdf->camera->gamma += 0.04 * fdf->camera->speed_rotate;
	}
	else if (keys->gamma_rotate)
		fdf->camera->gamma += 0.01;
}

void	rotate_R(t_fdf *fdf, t_keys *keys)
{
	if (keys->alpha_plus || fdf->keys->j)
		fdf->camera->alpha += 0.05;
	if (keys->alpha_minus || fdf->keys->k)
		fdf->camera->alpha -= 0.05;
	if (keys->beta_plus || (!fdf->keys->shift && fdf->keys->l))
		fdf->camera->beta += 0.05;
	if (keys->beta_minus || (!fdf->keys->shift && fdf->keys->h))
		fdf->camera->beta -= 0.05;
	if (keys->gamma_plus || (fdf->keys->shift && fdf->keys->l))
		fdf->camera->gamma += 0.05;
	if (keys->gamma_minus || (fdf->keys->shift && fdf->keys->h))
		fdf->camera->gamma -= 0.05;
	R(fdf, keys);
}
