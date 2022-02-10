#include "fdf.h"

static void	zoom_mouse(t_fdf *fdf, t_keys *keys)
{
	//обработка зума мышкой
	static int time = 0;
	if (keys->mouse_zoom == 1 && time != 5)
	{
		fdf->map->square_size += 1;
		fdf->camera->offset_y -= fdf->map->height_map / 3;
		time++;
		if (time == 5)
		{
			time = 0;
			keys->mouse_zoom = 0;
		}
	}
	if (keys->mouse_zoom == -1 && time != 5)
	{
		if (fdf->map->square_size >= 2)
		{
			fdf->map->square_size -= 1;
			fdf->camera->offset_y += fdf->map->height_map / 3;
		}
		time++;
		if (time == 5)
		{
			time = 0;
			keys->mouse_zoom = 0;
		}
	}
}

void	zoom(t_fdf *fdf, t_keys *keys)
{
	if (!keys->shift && keys->plus)
	{
		fdf->map->square_size += 1;
		fdf->camera->offset_y -= fdf->map->height_map / 3;
	}
	if (!keys->shift && keys->minus)
	{
		if (fdf->map->square_size >= 2)
		{
			fdf->map->square_size -= 1;
			fdf->camera->offset_y += fdf->map->height_map / 3;
		}
	}
	zoom_mouse(fdf, keys);
}
