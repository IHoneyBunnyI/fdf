#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include "xiaolin.h"

static void	_dla_plot(t_mlx *mlx, t_xy dot, t_rgb_color *col, float br)
{
	t_rgb_color oc;
	_dla_changebrightness(col, &oc, br);
	pixel_put(mlx, dot.x, dot.y, make_color(oc.red, oc.green, oc.blue));
}

static void	plot_(t_mlx *mlx, t_xy dot, double d, int c)
{
	t_rgb_color	f;

	f.red = get_r(c);
	f.green = get_g(c);
	f.blue = get_b(c);
	_dla_plot(mlx, dot, &f, d);
}

static void	draw_line_xiaolin_wu_util_1(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point cur;
	t_point delta;
	t_floatdx c;
	int x;

	cur = p1;
	delta.x = abs(p2.x - p1.x);
	delta.y = abs(p2.y - p1.y);
	c.sx = p1.x < p2.x ? 1 : -1;
	c.sy = p1.y < p2.y ? 1 : -1;

	c.dx = (double)p2.x - p1.x;
	c.dy = (double)p2.y - p1.y;
	if (p2.x < p1.x)
	{
		swap_(&p1.x, &p2.x);
		swap_(&p1.y, &p2.y);
	}
	fill_floatdx_p1x(&c, p1);
	plot_(fdf->mlx, (t_xy){c.xpxl1, c.ypxl1}, rfpart_(c.yend) * c.xgap, get_color(cur, p1, p2, delta));
	cur.x += c.sx;
	plot_(fdf->mlx, (t_xy){c.xpxl1, c.ypxl1 + 1}, fpart_(c.yend) * c.xgap, get_color(cur, p1, p2, delta));

	cur.y += c.sy;

	fill_floatdx_p2y(&c, p2);

	plot_(fdf->mlx, (t_xy){c.xpxl2, c.ypxl2}, rfpart_(c.yend) * c.xgap, get_color(cur, p1, p2, delta));
	plot_(fdf->mlx, (t_xy){c.xpxl2, c.ypxl2 + 1}, fpart_(c.yend) * c.xgap, get_color(cur, p1, p2, delta));

	x = c.xpxl1+1;
	while (x < c.xpxl2)
	{
		plot_(fdf->mlx, (t_xy){x,ipart_(c.intery)}, rfpart_(c.intery), get_color(cur, p1, p2, delta));
		plot_(fdf->mlx, (t_xy){x, ipart_(c.intery) + 1}, fpart_(c.intery), get_color(cur, p1, p2, delta));
		c.intery += c.gradient;
		cur.x += c.sx;
		x++;
	}
}

void	draw_line_xiaolin_wu_util_2(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point cur;
	t_point delta;
	t_floatdx c;
	int y;
	
	cur = p1;
	delta.x = abs(p2.x - p1.x);
	delta.y = abs(p2.y - p1.y);
	c.sy = p1.y < p2.y ? 1 : -1;
	c.dx = (double)p2.x - p1.x;
	c.dy = (double)p2.y - p1.y;

	if ( p2.y < p1.y ) {
		swap_(&p1.x, &p2.x);
		swap_(&p1.y, &p2.y);
	}
	c.gradient = c.dx / c.dy;
	c.yend = round_(p1.y);
	c.xend = p1.x + c.gradient*(c.yend - p1.y);
	c.ygap = rfpart_(p1.y + 0.5);
	c.ypxl1 = c.yend;
	c.xpxl1 = ipart_(c.xend);

	plot_(fdf->mlx, (t_xy){c.xpxl1, c.ypxl1}, rfpart_(c.xend)*c.ygap, get_color(cur, p1, p2, delta));
	plot_(fdf->mlx, (t_xy){c.xpxl1 + 1, c.ypxl1}, fpart_(c.xend)*c.ygap, get_color(cur, p1, p2, delta));

	c.interx = c.xend + c.gradient;
	c.yend = round_(p2.y);
	c.xend = p2.x + c.gradient * (c.yend - p2.y);
	c.ygap = fpart_(p2.y+0.5);
	c.ypxl2 = c.yend;
	c.xpxl2 = ipart_(c.xend);

	plot_(fdf->mlx, (t_xy){c.xpxl2, c.ypxl2}, rfpart_(c.xend) * c.ygap, get_color(cur, p1, p2, delta));
	plot_(fdf->mlx, (t_xy){c.xpxl2 + 1, c.ypxl2}, fpart_(c.xend) * c.ygap, get_color(cur, p1, p2, delta));

	y=c.ypxl1+1;
	while (y < c.ypxl2) {
		plot_(fdf->mlx, (t_xy){ipart_(c.interx), y}, rfpart_(c.interx), get_color(cur, p1, p2, delta));
		plot_(fdf->mlx, (t_xy){ipart_(c.interx) + 1, y}, fpart_(c.interx), get_color(cur, p1, p2, delta));
		c.interx += c.gradient;
		cur.y += c.sy;
		y++;
	}
}

void draw_line_xiaolin_wu(t_fdf *fdf, t_point p1, t_point p2)
{
	double dx;
	double dy;

	if (p1.x > WIDTH && p1.y > HEIGHT)
		return ;
	if (p1.x < 0 && p1.y < 0 && p2.x < 0 && p2.y < 0)
		return ;
	dx = (double)p2.x - p1.x;
	dy = (double)p2.y - p1.y;
	if (fabs(dx) > fabs(dy))
		draw_line_xiaolin_wu_util_1(fdf, p1, p2);
	else 
		draw_line_xiaolin_wu_util_2(fdf, p1, p2);
}
