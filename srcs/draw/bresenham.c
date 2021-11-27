#include "fdf.h"

#include <stdlib.h>
void draw_line_bresenham(t_mlx *mlx, t_point p0, t_point p1)
{

	int dx = abs((p1.x - p0.x));
	int sx = p0.x < p1.x ? 1 : -1;
	int dy = -abs(p1.y - p0.y);
	int sy = p0.y < p1.y ? 1 : -1;
	int err = dx + dy;
	t_point delta;
	delta.x = abs(p1.x - p0.x);
	delta.y = abs(p1.y - p0.y);
	t_point cur = p0;
	while (1)
	{
		pixel_put(mlx, cur.x, cur.y, get_color(cur, p0, p1, delta));
		if (cur.x == p1.x && cur.y == p1.y)
			break;
		int e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			cur.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			cur.y += sy;
		}
	}
}
