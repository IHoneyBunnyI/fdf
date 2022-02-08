#ifndef XIAOLIN_H
# define XIAOLIN_H
# include "fdf.h"

typedef struct s_floatdx
{
	double	dx;
	int		sx;
	double	dy;
	int		sy;
	double	err;
	double gradient;
	double xend;
	double yend;
	double xgap;
	double ygap;
	int xpxl1;
	int ypxl1;
	double intery;
	double interx;
	int xpxl2;
	int ypxl2;
}	t_floatdx;

typedef struct s_xiaolin
{
	t_point *p1;
	t_point *p2;
	t_point *cur;
	t_point *delta;
	t_floatdx *c;

}	t_xiaolin;

int		ipart_(double x);
int		round_(int x);
double	fpart_(double x);
double	rfpart_(double x);
void	swap_(int *a, int *b);
void	_dla_changebrightness(t_rgb_color* from, t_rgb_color* to, float br);
void	fill_floatdx_p1x_1(t_floatdx *c, t_point p1);
void	fill_floatdx_p2y_1(t_floatdx *c, t_point p1);
void	fill_floatdx_p1x_2(t_floatdx *c, t_point p1);
void	fill_floatdx_p2y_2(t_floatdx *c, t_point p2);
void	draw_line_xiaolin_wu_util_1_1(t_fdf *fdf, t_xiaolin *xiaolin);
void	plot_(t_mlx *mlx, t_xy dot, double d, int c);

#endif
