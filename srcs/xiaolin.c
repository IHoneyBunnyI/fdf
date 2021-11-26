#include "fdf.h"
#include <math.h>

typedef struct rgb_color
{
	int red;
	int green;
	int blue;
} t_rgb_color;

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

void plot_(int x,int y, double d)
{
	t_rgb_color f_;

	f_.red = color(255, 0, 0);
	f_.green = color(0, 255, 0);
	f_.blue = color(0, 0, 255);
}

inline void _dla_changebrightness(t_rgb_color* from, t_rgb_color* to, float br)
{
	if (br > 1.0)
		br = 1.0;
	/* linear... Maybe something more complex could give better look */
	to->red = br * (float)from->red;
	to->green = br * (float)from->green;
	to->blue = br * (float)from->blue;
}

inline void _dla_plot(t_mlx *mlx, int x, int y, t_rgb_color* col, float br)
{
	t_rgb_color oc;
	_dla_changebrightness(col, &oc, br);
	pixel_put(mlx, x, y, color(oc.red, oc.green, oc.blue));
}

void print_line_xiaolin_wu(t_mlx *mlx, t_point p1, t_point p2)
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
	}
	double gradient = dy / dx;
	double xend = round_(p1.x);
	double yend = p1.y + gradient *(xend - p1.x);
	double xgap = rfpart_(p1.x + 0.5);
	int xpxl1 = xend;
	int ypxl1 = ipart_(yend);
}

 
/*void draw_line_antialias( image img, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, color_component r, color_component g, color_component b )
{
	double dx = (double)x2 - (double)x1;
	double dy = (double)y2 - (double)y1;
	if ( fabs(dx) > fabs(dy) ) {
		if ( x2 < x1 ) {
			swap_(x1, x2);
			swap_(y1, y2);
		}
		double gradient = dy / dx;
		double xend = round_(x1);
		double yend = y1 + gradient*(xend - x1);
		double xgap = rfpart_(x1 + 0.5);
		int xpxl1 = xend;
		int ypxl1 = ipart_(yend);
		plot_(xpxl1, ypxl1, rfpart_(yend)*xgap);
		plot_(xpxl1, ypxl1+1, fpart_(yend)*xgap);
		double intery = yend + gradient;
 
		xend = round_(x2);
		yend = y2 + gradient*(xend - x2);
		xgap = fpart_(x2+0.5);
		int xpxl2 = xend;
		int ypxl2 = ipart_(yend);
		plot_(xpxl2, ypxl2, rfpart_(yend) * xgap);
		plot_(xpxl2, ypxl2 + 1, fpart_(yend) * xgap);
 
		int x;
		for(x=xpxl1+1; x < xpxl2; x++) {
			plot_(x, ipart_(intery), rfpart_(intery));
			plot_(x, ipart_(intery) + 1, fpart_(intery));
			intery += gradient;
		}
	} else {
		if ( y2 < y1 ) {
			swap_(x1, x2);
			swap_(y1, y2);
		}
		double gradient = dx / dy;
		double yend = round_(y1);
		double xend = x1 + gradient*(yend - y1);
		double ygap = rfpart_(y1 + 0.5);
		int ypxl1 = yend;
		int xpxl1 = ipart_(xend);
		plot_(xpxl1, ypxl1, rfpart_(xend)*ygap);
		plot_(xpxl1 + 1, ypxl1, fpart_(xend)*ygap);
		double interx = xend + gradient;
 
		yend = round_(y2);
		xend = x2 + gradient*(yend - y2);
		ygap = fpart_(y2+0.5);
		int ypxl2 = yend;
		int xpxl2 = ipart_(xend);
		plot_(xpxl2, ypxl2, rfpart_(xend) * ygap);
		plot_(xpxl2 + 1, ypxl2, fpart_(xend) * ygap);
 
		int y;
		for(y=ypxl1+1; y < ypxl2; y++) {
			plot_(ipart_(interx), y, rfpart_(interx));
			plot_(ipart_(interx) + 1, y, fpart_(interx));
			interx += gradient;
		}
	}
}*/
/*inline void _dla_changebrightness(rgb_color_p from, rgb_color_p to, float br)
{
	if ( br > 1.0 ) br = 1.0;
	/ linear... Maybe something more complex could give better look /
	to->red = br * (float)from->red;
	to->green = br * (float)from->green;
	to->blue = br * (float)from->blue;
}
 
#define plot_(X,Y,D) do{ rgb_color f_;				\
	f_.red = r; f_.green = g; f_.blue = b;			\
	_dla_plot(img, (X), (Y), &f_, (D)) ; }while(0)
 
inline void _dla_plot(image img, int x, int y, rgb_color_p col, float br)
{
	rgb_color oc;
	_dla_changebrightness(col, &oc, br);
	put_pixel_clip(img, x, y, oc.red, oc.green, oc.blue);
}
