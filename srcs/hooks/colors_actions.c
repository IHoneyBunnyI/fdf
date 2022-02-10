#include "fdf.h"
#include <stdlib.h>
#include <time.h>

static void	invert_color(t_fdf *fdf, t_keys *keys)
{
	if (!keys->option && !keys->shift && !keys->ctrl && keys->invert_color)
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
}

static void	random_color(t_fdf *fdf, t_keys *keys)
{
	if (keys->shift && keys->invert_color)
	{
		t_point **points;
		points = fdf->points;
		srand(time(0));
		int new_color  = rand() % 0xFFFFFF;
		for (int i = 0; i < fdf->map->height_map; i++)
		{
			for (int j = 0; j < fdf->map->width_map; j++)
					points[i][j].color = new_color;
		}
		keys->invert_color = 0;
	}
}

static void	rainbow_color(t_fdf *fdf, t_keys *keys)
{
	if (keys->ctrl && keys->invert_color)
	{
		t_point **points;
		points = fdf->points;
		srand(time(0));
		for (int i = 0; i < fdf->map->height_map; i++)
		{
			for (int j = 0; j < fdf->map->width_map; j++)
				if (points[i][j].color != 0xFFFFFF)
					points[i][j].color = rand() % 0xFFFFFF;
		}
		keys->invert_color = 0;
	}
}

static void reset_color(t_fdf *fdf, t_keys *keys)
{
	// вернуть первоначальные цвета
	if (keys->is_isometric || (keys->invert_color && keys->option))
	{
		for (int i = 0; i < fdf->map->height_map; i++)
		{
			for (int j = 0; j < fdf->map->width_map; j++)
			{
				if (fdf->points[i][j].color != 0xFFFFFF)
					fdf->points[i][j].color = fdf->points[i][j].first_color;
			}
		}
		keys->invert_color = 0;
	}
}

void	colors_actions(t_fdf *fdf, t_keys *keys)
{
	invert_color(fdf, keys);
	random_color(fdf, keys);
	rainbow_color(fdf, keys);
	reset_color(fdf, keys);
}
