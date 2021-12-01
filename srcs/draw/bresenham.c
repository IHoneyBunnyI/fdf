#include "fdf.h"

#include <stdlib.h>
#include <math.h>
void draw_line_bresenham(t_fdf *fdf, t_point p1, t_point p2)
{

		/*p1.x *= fdf->map->square_size;*/
		/*p2.x *= fdf->map->square_size;*/
		/*p1.y *= fdf->map->square_size;*/
		/*p2.y *= fdf->map->square_size;*/
		/*p1.z *= fdf->map->square_size;*/
		/*p2.z *= fdf->map->square_size;*/

		/*p1.x -= (fdf->map->width_map * fdf->map->square_size) / 2;*/
		/*p2.x -= (fdf->map->width_map * fdf->map->square_size) / 2;*/
		/*p1.y -= (fdf->map->height_map * fdf->map->square_size) / 2;*/
		/*p2.y -= (fdf->map->height_map * fdf->map->square_size) / 2;*/

		/*rotate_x(&p1, fdf->camera->alpha);*/
		/*rotate_x(&p2, fdf->camera->alpha);*/
		/*rotate_y(&p1, fdf->camera->beta);*/
		/*rotate_y(&p2, fdf->camera->beta);*/
		/*rotate_z(&p1, fdf->camera->gamma);*/
		/*rotate_z(&p2, fdf->camera->gamma);*/
		/*[>printf("%d\n", fdf->map->square_size);<]*/

		/*[>points[y][x].x -= (map->width_map * map->square_size) / 2;<]*/
		/*[>points[y][x].y -= (map->height_map * map->square_size) / 2;<]*/

		/*int prev_1_x = p1.x;*/
		/*int prev_2_x = p2.x;*/
		/*int prev_1_y = p1.y;*/
		/*int prev_2_y = p2.y;*/

		/*[>//OK, RABOTAET<]*/
		/*p1.x = (prev_1_x - prev_1_y) * cos(0.523599);*/
		/*p2.x = (prev_2_x - prev_2_y) * cos(0.523599);*/
		/*p1.y = (prev_1_x + prev_1_y -p1.z) * sin(0.523599);*/
		/*p2.y = (prev_2_x + prev_2_y -p2.z) * sin(0.523599);*/

		/*p1.x += (WIDTH / 2) + fdf->camera->offset_x;*/
		/*p2.x += (WIDTH / 2) + fdf->camera->offset_x;*/
		/*p1.y += (fdf->map->height_map * fdf->map->square_size) / 2 + fdf->camera->offset_y;*/
		/*p2.y += (fdf->map->height_map * fdf->map->square_size) / 2 + fdf->camera->offset_y;*/

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
