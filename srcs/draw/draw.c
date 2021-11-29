#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

void init_map_mlx_keys(t_fdf *fdf, t_map **map, t_mlx **mlx, t_keys **keys)
{
	*map = fdf->map;
	*mlx = fdf->mlx;
	*keys = fdf->keys;
}

void fill_image(t_mlx *mlx)
{
	int size;

	size = WIDTH * HEIGHT * (mlx->bpp / 8);
	while (size--)
		mlx->addr[size] = 0;
}

t_point make_point(int x, int y, int color)
{
	t_point point;
	point.x = x;
	point.y = y;
	if (color == 0)
		point.color = make_color(255, 255, 255);
	else
		point.color = color;
	return (point);
}

void check_keys(t_fdf *fdf, t_keys *keys)
{
	if (keys->w)
		fdf->map->square_size += 1;
	if (keys->s)
		if (fdf->map->square_size > 2)
			fdf->map->square_size -= 1;

	if (keys->left)
		if (fdf->map->offset_x > 1)
			fdf->map->offset_x -= 3;
	if (keys->right)
			fdf->map->offset_x += 3;
	if (keys->up)
		if (fdf->map->offset_x > 0)
			fdf->map->offset_y -= 3;
	if (keys->down)
		fdf->map->offset_y += 3;
}

int draw(t_fdf *fdf, t_mlx *mlx)
{
	t_map *map;
	t_keys *keys;
	t_point **points;

	points = fdf->points;
	init_map_mlx_keys(fdf, &map, &mlx, &keys);
	fill_image(mlx);
	check_keys(fdf, keys);

	for (int i = 0; i < map->height_map - 1; ++i)
	{
		for (int j = 0; j < map->width_map - 1; ++j)
		{
			if (i == map->height_map - 2)
				draw_line_xiaolin_wu(fdf, points[i + 1][j], points[i + 1][j + 1]);
			if (j == map->width_map - 2)
				draw_line_xiaolin_wu(fdf, points[i][j + 1], points[i + 1][j + 1]);
			draw_line_xiaolin_wu(fdf, points[i][j], points[i][j + 1]);
			draw_line_xiaolin_wu(fdf, points[i][j], points[i + 1][j]);
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return 1;
}
