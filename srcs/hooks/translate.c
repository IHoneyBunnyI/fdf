#include "fdf.h"

void	translate(t_fdf *fdf, t_keys *keys)
{
	if (keys->a || keys->left)
			fdf->camera->offset_x -= 3;
	if (keys->d || keys->right)
			fdf->camera->offset_x += 3;
	if (keys->w || keys->up)
			fdf->camera->offset_y -= 3;
	if (keys->s || keys->down)
			fdf->camera->offset_y += 3;
}
