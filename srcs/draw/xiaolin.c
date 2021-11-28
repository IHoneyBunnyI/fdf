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

void draw_line_xiaolin_wu(t_mlx *mlx, t_point p1_in, t_point p2_in)
{
	int x1;
	int x2;
	int y1;
	int y2;

	x1 = p1_in.x;
	x2 = p2_in.x;
	y1 = p1_in.y;
	y2 = p2_in.y;

	t_point p1;
	t_point p2;
	p1.color = p1_in.color;
	p2.color = p2_in.color;
	p1.x = (x1 - y1) * 30 + WIDTH / 2;
	p1.y =  ((x1 + y1) - p1_in.z) * 15  + HEIGHT / 3;

	p2.x = (x2 - y2) * 30 + WIDTH / 2;
	p2.y =  ((x2 + y2) - p2_in.z) * 15  + HEIGHT / 3;




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
		double intery = yend + gradient;

		xend = round_(p2.x);
		yend = p2.y + gradient*(xend - p2.x);
		xgap = fpart_(p2.x+0.5);
		int xpxl2 = xend;
		int ypxl2 = ipart_(yend);
		plot_(mlx, xpxl2, ypxl2, rfpart_(yend) * xgap, get_color(cur, p1, p2, delta));
		plot_(mlx, xpxl2, ypxl2 + 1, fpart_(yend) * xgap, get_color(cur, p1, p2, delta));

		int x;
		for(x=xpxl1+1; x < xpxl2; x++) {
			plot_(mlx, x, ipart_(intery), rfpart_(intery), get_color(cur, p1, p2, delta));
			plot_(mlx, x, ipart_(intery) + 1, fpart_(intery), get_color(cur, p1, p2, delta));
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
