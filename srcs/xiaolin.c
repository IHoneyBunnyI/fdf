#include "fdf.h"
#include <math.h>

void swap_(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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
	/* linear... Maybe something more complex could give better look */
	to->red = br * (float)from->red;
	to->green = br * (float)from->green;
	to->blue = br * (float)from->blue;
}

void _dla_plot(t_mlx *mlx, int x, int y, t_rgb_color* col, float br)
{
	t_rgb_color oc;
	_dla_changebrightness(col, &oc, br);
	pixel_put(mlx, x, y, color(oc.red, oc.green, oc.blue));
}

void plot_(t_mlx *mlx, int x,int y, double d, int c)
{
	t_rgb_color f;

	f.red = get_r(c);
	f.green = get_g(c);
	f.blue = get_b(c);
	_dla_plot(mlx, x, y, &f, d);
}


#include <stdlib.h>

void draw_line_xiaolin_wu(t_mlx *mlx, t_point p1, t_point p2)
{
	/*int color_ = color(10, 100, 200);*/
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

		plot_(mlx, xpxl1, ypxl1, rfpart_(yend)*xgap, get_color(cur, p1, p2, delta));
		cur.x += sx;
		plot_(mlx, xpxl1, ypxl1+1, fpart_(yend)*xgap, get_color(cur, p1, p2, delta));
		cur.y += sy;
		/*plot_(mlx, xpxl1, ypxl1, rfpart_(yend)*xgap, color_);*/
		/*plot_(mlx, xpxl1, ypxl1+1, fpart_(yend)*xgap, color_);*/
		double intery = yend + gradient;

		xend = round_(p2.x);
		yend = p2.y + gradient*(xend - p2.x);
		xgap = fpart_(p2.x+0.5);
		int xpxl2 = xend;
		int ypxl2 = ipart_(yend);
		plot_(mlx, xpxl2, ypxl2, rfpart_(yend) * xgap, get_color(cur, p1, p2, delta));
		/*cur.x += sx;*/
		/*cur.y += sy;*/
		plot_(mlx, xpxl2, ypxl2 + 1, fpart_(yend) * xgap, get_color(cur, p1, p2, delta));
		/*cur.x += sx;*/
		/*cur.y += sy;*/
		/*plot_(mlx, xpxl2, ypxl2, rfpart_(yend) * xgap, color_);*/
		/*plot_(mlx, xpxl2, ypxl2 + 1, fpart_(yend) * xgap, color_);*/

		int x;
		for(x=xpxl1+1; x < xpxl2; x++) {
			/*int dx = abs((p1.x - p0.x));*/
			/*int sy = p1.y < p2.y ? 1 : -1;*/
			plot_(mlx, x, ipart_(intery), rfpart_(intery), get_color(cur, p1, p2, delta));
			plot_(mlx, x, ipart_(intery) + 1, fpart_(intery), get_color(cur, p1, p2, delta));
			/*plot_(mlx, x, ipart_(intery), rfpart_(intery), color_);*/
			/*plot_(mlx, x, ipart_(intery) + 1, fpart_(intery), color_);*/
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
		plot_(mlx, xpxl1, ypxl1, rfpart_(xend)*ygap, get_color(cur, p1, p2, delta));
		plot_(mlx, xpxl1 + 1, ypxl1, fpart_(xend)*ygap, get_color(cur, p1, p2, delta));
		double interx = xend + gradient;
 
		yend = round_(p2.y);
		xend = p2.x + gradient*(yend - p2.y);
		ygap = fpart_(p2.y+0.5);
		int ypxl2 = yend;
		int xpxl2 = ipart_(xend);
		plot_(mlx, xpxl2, ypxl2, rfpart_(xend) * ygap, get_color(cur, p1, p2, delta));
		plot_(mlx, xpxl2 + 1, ypxl2, fpart_(xend) * ygap, get_color(cur, p1, p2, delta));
 
		int y;
		for(y=ypxl1+1; y < ypxl2; y++) {
			plot_(mlx, ipart_(interx), y, rfpart_(interx), get_color(cur, p1, p2, delta));
			plot_(mlx, ipart_(interx) + 1, y, fpart_(interx), get_color(cur, p1, p2, delta));
			interx += gradient;
			cur.y += sy;
		}
	}
}
