#include "xiaolin.h"

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
