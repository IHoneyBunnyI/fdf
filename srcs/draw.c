#include "fdf.h"
#include "mlx.h"

void init_map_mlx_keys(t_fdf *fdf, t_map **map, t_mlx **mlx, t_keys **keys)
{
	*map = fdf->map;
	*mlx = fdf->mlx;
	*keys = fdf->keys;
}

void fill_image(t_mlx *mlx)
{
	int x;
	int y;
	int c;

	x = 0;
	y = 0;

	c = color(101, 200, 120);
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			pixel_put(mlx, x, y, c);
			y++;
		}
		y = 0;
		x++;
	}
}


#include <stdlib.h>
#include <time.h>
#include <math.h>
void put_rect(t_fdf *fdf, t_mlx *mlx)
{
	int x =	fdf->pos_x - (W_RECT / 2);
	int y =	fdf->pos_y - (W_RECT / 2);

	while (x < fdf->pos_x + W_RECT / 2)
	{
		while (y < fdf->pos_y + W_RECT / 2)
		{
			/*pixel_put(mlx, x, y, color(0, rand() % 200, rand() % 100, rand() % 200));*/
			pixel_put(mlx, x, y, color(200, 100, 200));
			y++;
		}
		y = fdf->pos_y - (W_RECT / 2);
		x++;
	}
}

void check_keys(t_fdf *fdf, t_keys *keys)
{
	/*printf("x = %d, y = %d\n", fdf->pos_x, fdf->pos_y);*/
	if (keys->w)
		fdf->pos_y -= 10;
	if (keys->s)
		fdf->pos_y += 10;
	if (keys->a)
		fdf->pos_x -= 10;
	if (keys->d)
		fdf->pos_x += 10;

	if (fdf->pos_y <= 0)
		fdf->pos_y = HEIGHT;
	if (fdf->pos_y >= HEIGHT + 4)
		fdf->pos_y = 0;

	if (fdf->pos_x <= 0)
		fdf->pos_x = WIDTH;
	if (fdf->pos_x >= WIDTH + 4)
		fdf->pos_x = 0;
}

int draw(t_fdf *fdf, t_mlx *mlx)
{
	t_map *map;
	t_keys *keys;
	t_point point1;
	t_point point2;

	point1.x = 10;
	point1.y = 10;
	point2.x = 200;
	point2.y = 100;

	init_map_mlx_keys(fdf, &map, &mlx, &keys);
	check_keys(fdf, keys);

	fill_image(mlx);


	draw_line_bresenham(mlx, point1, point2);
	point1.x = 100;
	point1.y = 10;
	point2.x = 200;
	point2.y = 300;
	draw_line_bresenham(mlx, point1, point2);
	point1.x = 400;
	point1.y = 100;
	point2.x = 250;
	point2.y = 350;
	draw_line_bresenham(mlx, point1, point2);

	put_rect(fdf, mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return 1;
}
