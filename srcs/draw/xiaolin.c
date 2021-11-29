#include "fdf.h"
#include <math.h>
#include <stdlib.h>


int ipart_(double x)
{
	return (int)x;
}

int round_(int x)
{
	return ((int)(((double)(x))+0.5));
}

double fpart_(double x)
{
	return (((double)(x))-(double)ipart_(x));
}

double rfpart_(double x)
{
	return (1.0-fpart_(x));
}

void _dla_changebrightness(t_rgb_color* from, t_rgb_color* to, float br)
{
	if (br > 1.0)
		br = 1.0;
	to->red = br * (float)from->red;
	to->green = br * (float)from->green;
	to->blue = br * (float)from->blue;
}

void _dla_plot(t_mlx *mlx, int x, int y, t_rgb_color* col, float br)
{
	t_rgb_color oc;
	_dla_changebrightness(col, &oc, br);
	pixel_put(mlx, x, y, make_color(oc.red, oc.green, oc.blue));
}

void plot_(t_mlx *mlx, int x,int y, double d, int c)
{
	t_rgb_color f;

	f.red = get_r(c);
	f.green = get_g(c);
	f.blue = get_b(c);
	_dla_plot(mlx, x, y, &f, d);
}

void	rotate_x(t_point *p, double alpha)
{
	int previous_y;

	previous_y = p->y;
	p->y = previous_y * cos(alpha) + p->z * sin(alpha);
	p->z = -previous_y * sin(alpha) + p->z * cos(alpha);
}

void	rotate_y(t_point *p, double beta)
{
	int previous_x;

	previous_x = p->x;
	p->x = previous_x * cos(beta) + p->z * sin(beta);
	p->z = -previous_x * sin(beta) + p->z * cos(beta);
}


void	rotate_z(t_point *p, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = previous_x * cos(gamma) - previous_y * sin(gamma);
	p->y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

#include <unistd.h>
void draw_line_xiaolin_wu(t_fdf *fdf, t_point p1, t_point p2)
{
	t_map *map = fdf->map;
	/*t_point p1 = p2_in;*/
	/*t_point p2 = p2_in;*/
	/*map->square_size = 0;*/

	/*int offset_x =  map->square_size * map->height_map;*/
	/*int offset_y = (HEIGHT - ((map->square_size / 2) * fdf->map->height_map)) / 2;*/

	//FIRST_V
	int x1;
	int x2;
	int y1;
	int y2;
	x1 = p1.x;
	x2 = p2.x;
	y1 = p1.y;
	y2 = p2.y;
	/*printf("%d\n", p1.x);*/

	p1.color = p1.color;
	p2.color = p2.color;

	p1.x *= map->square_size;
	p1.y *= map->square_size;
	p2.x *= map->square_size;
	p2.y *= map->square_size;
	p1.z *= map->square_size;
	p2.z *= map->square_size;

	p1.x -= (fdf->map->width_map * fdf->map->square_size) / 2;
	p2.x -= (fdf->map->width_map * fdf->map->square_size) / 2;
	p1.y -= (fdf->map->height_map * fdf->map->square_size) / 2;
	p2.y -= (fdf->map->height_map * fdf->map->square_size) / 2;

	rotate_x(&p1, fdf->camera->alpha);
	rotate_x(&p2, fdf->camera->alpha);
	rotate_y(&p1, fdf->camera->beta);
	rotate_y(&p2, fdf->camera->beta);
	rotate_z(&p1, fdf->camera->gamma);
	rotate_z(&p2, fdf->camera->gamma);

	p1.x += (fdf->map->width_map * fdf->map->square_size) / 2;
	p2.x += (fdf->map->width_map * fdf->map->square_size) / 2;
	p1.y += (fdf->map->height_map * fdf->map->square_size) / 2;
	p2.y += (fdf->map->height_map * fdf->map->square_size) / 2;

	int prev_1_x = p1.x;
	int prev_2_x = p2.x;
	int prev_1_y = p1.y;
	int prev_2_y = p2.y;

	//OK, RABOTAET
	p1.x = (prev_1_x - prev_1_y) * cos(0.523599);
	p2.x = (prev_2_x - prev_2_y) * cos(0.523599);

	p1.y = (prev_1_x + prev_1_y -p1.z) * sin(0.523599);
	p2.y = (prev_2_x + prev_2_y -p2.z) * sin(0.523599);

	p1.x += /*(WIDTH / 2) + */fdf->map->offset_x;
	p2.x += /*(WIDTH / 2) +  */fdf->map->offset_x;
	p1.y += /*(HEIGHT + fdf->map->height_map * fdf->map->square_size) / 2 + */fdf->map->offset_y;
	p2.y += /*(HEIGHT + fdf->map->height_map * fdf->map->square_size) / 2 + */fdf->map->offset_y;
	/*p1.x = (x1 - y1) * cos(0.523599) + map->offset_x;*/
	/*p1.y =  ((x1 + y1) - p1.z) *sin(0.523599) + map->offset_y;*/

	/*p2.x = (x2 - y2)  * cos(0.523599) + map->offset_x;*/
	/*p2.y =  ((x2 + y2) - p2.z)  * sin(0.523599)+ map->offset_y;*/


	/*p.x += (WIDTH - MENU_WIDTH) / 2 + fdf->camera->x_offset + MENU_WIDTH;*/
	/*p.y += (HEIGHT + fdf->map->height * fdf->camera->zoom) / 2*/












	//DRAW
	double dx = (double)p2.x - p1.x;
	double dy = (double)p2.y - p1.y;
	t_point cur = p1;
	t_point delta;
	delta.x = abs(p2.x - p1.x);
	delta.y = abs(p2.y - p1.y);

	int sx = p1.x < p2.x ? 1 : -1;
	int sy = p1.y < p2.y ? 1 : -1;
	if (fabs(dx) > fabs(dy))
	{
		if (p2.x < p1.x)
		{
			swap_(&p1.x, &p2.x);
			swap_(&p1.y, &p2.y);
		}
		double gradient = dy / dx;
		double xend = round_(p1.x);
		double yend = p1.y + gradient *(xend - p1.x);
		double xgap = rfpart_(p1.x + 0.5);
		int xpxl1 = xend;
		int ypxl1 = ipart_(yend);

		plot_(fdf->mlx, xpxl1, ypxl1, rfpart_(yend)*xgap, get_color(cur, p1, p2, delta));
		cur.x += sx;
		plot_(fdf->mlx, xpxl1, ypxl1+1, fpart_(yend)*xgap, get_color(cur, p1, p2, delta));
		cur.y += sy;
		double intery = yend + gradient;

		xend = round_(p2.x);
		yend = p2.y + gradient*(xend - p2.x);
		xgap = fpart_(p2.x+0.5);
		int xpxl2 = xend;
		int ypxl2 = ipart_(yend);
		plot_(fdf->mlx, xpxl2, ypxl2, rfpart_(yend) * xgap, get_color(cur, p1, p2, delta));
		plot_(fdf->mlx, xpxl2, ypxl2 + 1, fpart_(yend) * xgap, get_color(cur, p1, p2, delta));

		int x;
		for(x=xpxl1+1; x < xpxl2; x++) {
			plot_(fdf->mlx, x, ipart_(intery), rfpart_(intery), get_color(cur, p1, p2, delta));
			plot_(fdf->mlx, x, ipart_(intery) + 1, fpart_(intery), get_color(cur, p1, p2, delta));
			intery += gradient;
			cur.x += sx;
		}
	}
	else 
	{
		if ( p2.y < p1.y ) {
			swap_(&p1.x, &p2.x);
			swap_(&p1.y, &p2.y);
		}
		double gradient = dx / dy;
		double yend = round_(p1.y);
		double xend = p1.x + gradient*(yend - p1.y);
		double ygap = rfpart_(p1.y + 0.5);
		int ypxl1 = yend;
		int xpxl1 = ipart_(xend);
		plot_(fdf->mlx, xpxl1, ypxl1, rfpart_(xend)*ygap, get_color(cur, p1, p2, delta));
		plot_(fdf->mlx, xpxl1 + 1, ypxl1, fpart_(xend)*ygap, get_color(cur, p1, p2, delta));
		double interx = xend + gradient;
 
		yend = round_(p2.y);
		xend = p2.x + gradient*(yend - p2.y);
		ygap = fpart_(p2.y+0.5);
		int ypxl2 = yend;
		int xpxl2 = ipart_(xend);
		plot_(fdf->mlx, xpxl2, ypxl2, rfpart_(xend) * ygap, get_color(cur, p1, p2, delta));
		plot_(fdf->mlx, xpxl2 + 1, ypxl2, fpart_(xend) * ygap, get_color(cur, p1, p2, delta));
 
		int y;
		for(y=ypxl1+1; y < ypxl2; y++) {
			plot_(fdf->mlx, ipart_(interx), y, rfpart_(interx), get_color(cur, p1, p2, delta));
			plot_(fdf->mlx, ipart_(interx) + 1, y, fpart_(interx), get_color(cur, p1, p2, delta));
			interx += gradient;
			cur.y += sy;
		}
	}
}
