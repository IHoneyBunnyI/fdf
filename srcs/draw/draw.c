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

int draw(t_fdf *fdf, t_mlx *mlx)
{
	t_map *map;
	t_keys *keys;
	t_point **points;

	points = fdf->points;
	init_map_mlx_keys(fdf, &map, &mlx, &keys);
	fill_image(mlx);
	check_keys(fdf, keys);

	/*for (int i = 0; i < map->height_map - 1; ++i)*/
	/*{*/
		/*for (int j = 0; j < map->width_map - 1; ++j)*/
		/*{*/
			/*if (i == map->height_map - 2)*/
				/*draw_line_bresenham(fdf, set_point(fdf, points[i + 1][j]), set_point(fdf, points[i + 1][j + 1]));*/
			/*if (j == map->width_map - 2)*/
				/*draw_line_bresenham(fdf, set_point(fdf, points[i][j + 1]), set_point(fdf, points[i + 1][j + 1]));*/
			/*draw_line_bresenham(fdf, set_point(fdf, points[i][j]), set_point(fdf, points[i][j + 1]));*/
			/*draw_line_bresenham(fdf, set_point(fdf, points[i][j]), set_point(fdf, points[i + 1][j]));*/
		/*}*/
	/*}*/

	for (int i = 0; i < map->height_map - 1; ++i)
	{
		for (int j = 0; j < map->width_map - 1; ++j)
		{
			if (i == map->height_map - 2)
				draw_line_xiaolin_wu(fdf, set_point(fdf, points[i + 1][j]), set_point(fdf, points[i + 1][j + 1]));
			if (j == map->width_map - 2)
				draw_line_xiaolin_wu(fdf, set_point(fdf, points[i][j + 1]), set_point(fdf, points[i + 1][j + 1]));
			draw_line_xiaolin_wu(fdf, set_point(fdf, points[i][j]), set_point(fdf, points[i][j + 1]));
			draw_line_xiaolin_wu(fdf, set_point(fdf, points[i][j]), set_point(fdf, points[i + 1][j]));
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return 1;
}
