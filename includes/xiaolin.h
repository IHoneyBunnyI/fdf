#ifndef XIAOLIN_H
# define XIAOLIN_H
# include "fdf.h"

int		ipart_(double x);
int		round_(int x);
double	fpart_(double x);
double	rfpart_(double x);
void	_dla_changebrightness(t_rgb_color* from, t_rgb_color* to, float br);
void fill_floatdx_p1x(t_floatdx *c, t_point p1);
void fill_floatdx_p2y(t_floatdx *c, t_point p1);

#endif
