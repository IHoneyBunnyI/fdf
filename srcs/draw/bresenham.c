#include "fdf.h"

#include <stdlib.h>
#include <math.h>
void draw_line_bresenham(t_fdf *fdf, t_point p1, t_point p2)
{
	int dx = abs((p2.x - p1.x));
	int sx = p1.x < p2.x ? 1 : -1;
	int dy = -abs(p2.y - p1.y);
	int sy = p1.y < p2.y ? 1 : -1;
	int err = dx + dy;
	t_point delta;
	delta.x = abs(p2.x - p1.x);
	delta.y = abs(p2.y - p1.y);
	t_point cur = p1;
	while (1)
	{
		pixel_put(fdf->mlx, cur.x, cur.y, get_color(cur, p1, p2, delta));
		if (cur.x == p2.x && cur.y == p2.y)
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
