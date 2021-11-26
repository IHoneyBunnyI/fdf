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

void plot_(t_mlx *mlx, int x,int y, double d, t_rgb_color c)
{
	t_rgb_color f_;

	f_.red = c.red;
	f_.green = c.green;
	f_.blue = c.blue;
	_dla_plot(mlx, x, y, &f_, d);
}



void draw_line_xiaolin_wu(t_mlx *mlx, t_point p1, t_point p2, t_rgb_color c)
{
	double dx = (double)p2.x - p1.x;
	double dy = (double)p2.y - p1.y;
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
		/*plot_(*/
		plot_(mlx, xpxl1, ypxl1, rfpart_(yend)*xgap, c);
		plot_(mlx, xpxl1, ypxl1+1, fpart_(yend)*xgap, c);
		double intery = yend + gradient;

		xend = round_(p2.x);
		yend = p2.y + gradient*(xend - p2.x);
		xgap = fpart_(p2.x+0.5);
		int xpxl2 = xend;
		int ypxl2 = ipart_(yend);
		plot_(mlx, xpxl2, ypxl2, rfpart_(yend) * xgap, c);
		plot_(mlx, xpxl2, ypxl2 + 1, fpart_(yend) * xgap, c);

		int x;
		for(x=xpxl1+1; x < xpxl2; x++) {
			plot_(mlx, x, ipart_(intery), rfpart_(intery), c);
			plot_(mlx, x, ipart_(intery) + 1, fpart_(intery), c);
			intery += gradient;
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
		plot_(mlx, xpxl1, ypxl1, rfpart_(xend)*ygap, c);
		plot_(mlx, xpxl1 + 1, ypxl1, fpart_(xend)*ygap, c);
		double interx = xend + gradient;
 
		yend = round_(p2.y);
		xend = p2.x + gradient*(yend - p2.y);
		ygap = fpart_(p2.y+0.5);
		int ypxl2 = yend;
		int xpxl2 = ipart_(xend);
		plot_(mlx, xpxl2, ypxl2, rfpart_(xend) * ygap, c);
		plot_(mlx, xpxl2 + 1, ypxl2, fpart_(xend) * ygap, c);
 
		int y;
		for(y=ypxl1+1; y < ypxl2; y++) {
			plot_(mlx, ipart_(interx), y, rfpart_(interx), c);
			plot_(mlx, ipart_(interx) + 1, y, fpart_(interx), c);
			interx += gradient;
		}
	}
}
