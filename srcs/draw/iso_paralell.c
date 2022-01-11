#include "fdf.h"
#include <math.h>

void iso(t_fdf *fdf, t_point *p1, t_point *p2)
{
	int previous_1_x;
	int previous_1_y;
	int previous_2_x;
	int previous_2_y;

	fdf->camera->offset_x = 0;
	fdf->camera->offset_y = 0;
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	p1->x += (fdf->map->width_map * fdf->map->square_size) / 2;
	p2->x += (fdf->map->width_map * fdf->map->square_size) / 2;
	p1->y += (fdf->map->height_map * fdf->map->square_size) / 2;
	p2->y += (fdf->map->height_map * fdf->map->square_size) / 2;
	previous_1_x = p1->x;
	previous_1_y = p1->y;
	previous_2_x = p2->x;
	previous_2_y = p2->y;
	p1->x = (previous_1_x - previous_1_y) * cos(0.523599);
	p1->y = (previous_1_x + previous_1_y - p1->z) * sin(0.523599);
	p2->x = (previous_2_x - previous_2_y) * cos(0.523599);
	p2->y = (previous_2_x + previous_2_y - p2->z) * sin(0.523599);
	p1->x += (WIDTH / 2);
	p2->x += (WIDTH / 2);
	p1->y += (fdf->map->height_map * fdf->map->square_size) / 2;
	p2->y += (fdf->map->height_map * fdf->map->square_size) / 2;
}

void parallel(t_fdf *fdf, t_point *p1, t_point *p2)
{
	p1->x *= fdf->map->square_size;
	p2->x *= fdf->map->square_size;
	p1->y *= fdf->map->square_size;
	p2->y *= fdf->map->square_size;
	p1->z *= fdf->map->square_size;
	p2->z *= fdf->map->square_size;
	fdf->camera->offset_x = 0;
	fdf->camera->offset_y = 0;
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
}
