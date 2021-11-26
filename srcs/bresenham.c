#include "fdf.h"

#include <stdlib.h>
void draw_line_bresenham(t_mlx *mlx, t_point p0, t_point p1)
{
	/*int dx = p1.x - p0.x;*/
	/*int dy = p1.y - p0.y;*/
	/*int D = 2 * dy - dx;*/
	/*int y = p0.y;*/

	/*for (int x = p0.x; x < p1.x; x++)*/
	/*{*/
		/*pixel_put(mlx, x, y, color(0, 100, 20, 200));*/
		/*if (D > 0)*/
		/*{*/
			/*y = y + 1;*/
			/*D = D - 2 * dx;*/
		/*}*/
		/*D = D + 2 * dy;*/
	/*}*/

	int dx = abs((p1.x - p0.x));
	int sx = p0.x < p1.x ? 1 : -1;
	int dy = -abs(p1.y - p0.y);
	int sy = p0.y < p1.y ? 1 : -1;
	int err = dx + dy;
	while (1)
	{
		pixel_put(mlx, p0.x, p0.y, color(100, 20, 200));
		if (p0.x == p1.x && p0.y == p1.y)
			break;
		int e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			p0.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			p0.y += sy;
		}
	}
}
