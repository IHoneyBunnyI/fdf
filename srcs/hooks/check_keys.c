#include "fdf.h"

void	check_keys(t_fdf *fdf, t_keys *keys)
{
	zoom(fdf, keys);
	translate(fdf, keys);
	rotate_R(fdf, keys);
	colors_actions(fdf, keys);

	// увеличить координату z
	if (keys->shift && keys->plus)
	{
		if (fdf->camera->z_coefficient < 10)
			fdf->camera->z_coefficient += 0.05;
	}
	// уменьшить координату z
	if (keys->shift && keys->minus)
	{
		if (fdf->camera->z_coefficient > -0.5)
			fdf->camera->z_coefficient -= 0.05;
	}
}

