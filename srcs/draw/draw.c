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
	int x;
	int y;

	x = 0;
	y = 0;

	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			pixel_put(mlx, x, y, 0);
			y++;
		}
		y = 0;
		x++;
	}
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

	init_map_mlx_keys(fdf, &map, &mlx, &keys);
	fill_image(mlx);
	check_keys(fdf, keys);


	point1 = make_point(WIDTH / 2, HEIGHT / 2, 0xFF0000);
	/*point2 = make_point(0, 0, make_color(0, 255, 0));*/
	int r = 150;
	point2.color = make_color(100, 20, 255);
	for (int angle = 0; angle <= 360; angle += 2)
	{
		/*draw_line_bresenham(mlx, point1, point2);*/
		point2.x = point1.x + r * cos((float)(((float)angle * 3.14)/180));
		point2.y = point1.y + r * sin((float)(((float)angle * 3.14)/180));
		/*point2.x = point1.x + r * cos(angle);*/
		/*point2.y = point1.y + r * sin(angle);*/
		draw_line_xiaolin_wu(mlx, point1, point2);
	}

	r = 50;
	point1 = make_point(100, 100, 0x00FF00);
	point2.color = make_color(180, 2, 60);
	for (int angle = 0; angle <= 360; angle += 2)
	{
		/*draw_line_bresenham(mlx, point1, point2);*/
		point2.x = point1.x + r * cos((float)(((float)angle * 3.14)/180));
		point2.y = point1.y + r * sin((float)(((float)angle * 3.14)/180));
		/*point2.x = point1.x + r * cos(angle);*/
		/*point2.y = point1.y + r * sin(angle);*/
		draw_line_xiaolin_wu(mlx, point1, point2);
	}

	r = 50;
	point1 = make_point(WIDTH - 100, 100, 0x00FF00);
	point2.color = make_color(180, 2, 60);
	for (int angle = 0; angle <= 360; angle += 2)
	{
		/*draw_line_bresenham(mlx, point1, point2);*/
		point2.x = point1.x + r * cos((float)(((float)angle * 3.14)/180));
		point2.y = point1.y + r * sin((float)(((float)angle * 3.14)/180));
		/*point2.x = point1.x + r * cos(angle);*/
		/*point2.y = point1.y + r * sin(angle);*/
		draw_line_xiaolin_wu(mlx, point1, point2);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return 1;
}
