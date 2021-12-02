#include "fdf.h"
#include <math.h>

t_point set_point(t_fdf *fdf, t_point p)
{

	if (fdf->keys->is_isometric)
	{
		/*fdf->camera->alpha = -0.785398;*/
		/*fdf->camera->beta =  -0.628318;*/
		/*fdf->camera->gamma =  0.523598;*/
		fdf->camera->offset_x = 0;
		fdf->camera->offset_y = 0;
		fdf->camera->alpha = 0.;
		fdf->camera->beta = 0.;
		fdf->camera->gamma = 0;
	}
	float prev_a = fdf->camera->alpha;
	float prev_b = fdf->camera->beta;
	float prev_g = fdf->camera->gamma;
	if (fdf->keys->is_parralel)
	{
		fdf->camera->alpha = 0;
		fdf->camera->beta = 0;
		fdf->camera->gamma = 0;
	}
	p.x *= fdf->map->square_size;
	p.y *= fdf->map->square_size;
	p.z *= fdf->map->square_size;
	p.x -= (fdf->map->width_map * fdf->map->square_size) / 2;
	p.y -= (fdf->map->height_map * fdf->map->square_size) / 2;

	/*printf("a=%f b=%f g=%f\n", fdf->camera->alpha, fdf->camera->beta, fdf->camera->gamma);*/

	rotate_x(&p, fdf->camera->alpha);
	rotate_y(&p, fdf->camera->beta);
	rotate_z(&p, fdf->camera->gamma);

	int prev_1_x;
	int prev_1_y;
	prev_1_x = p.x;
	prev_1_y = p.y;
	if (!fdf->keys->is_parralel)
	{
		p.x = (prev_1_x - prev_1_y) * cos(0.523599);
		p.y = (prev_1_x + prev_1_y -p.z) * sin(0.523599);
	}
	fdf->camera->alpha = prev_a;
	fdf->camera->beta = prev_b;
	fdf->camera->gamma = prev_g;
	p.x += (WIDTH / 2) + fdf->camera->offset_x;
	p.y += (fdf->map->height_map * fdf->map->square_size) + fdf->camera->offset_y;
	return (p);
}
