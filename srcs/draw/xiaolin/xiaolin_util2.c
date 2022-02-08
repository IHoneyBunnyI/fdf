#include "xiaolin.h"

void fill_floatdx_p1x_1(t_floatdx *c, t_point p1)
{
	c->gradient = c->dy / c->dx;
	c->xend = round_(p1.x);
	c->yend = p1.y + c->gradient * (c->xend - p1.x);
	c->xgap = rfpart_(p1.x + 0.5);
	c->xpxl1 = c->xend;
	c->ypxl1 = ipart_(c->yend);
}

void fill_floatdx_p2y_1(t_floatdx *c, t_point p2)
{
	c->intery = c->yend + c->gradient;
	c->xend = round_(p2.x);
	c->yend = p2.y + c->gradient * (c->xend - p2.x);
	c->xgap = fpart_(p2.x + 0.5);
	c->xpxl2 = c->xend;
	c->ypxl2 = ipart_(c->yend);
}

void fill_floatdx_p1x_2(t_floatdx *c, t_point p1)
{
	c->gradient = c->dx / c->dy;
	c->yend = round_(p1.y);
	c->xend = p1.x + c->gradient*(c->yend - p1.y);
	c->ygap = rfpart_(p1.y + 0.5);
	c->ypxl1 = c->yend;
	c->xpxl1 = ipart_(c->xend);
}

void fill_floatdx_p2y_2(t_floatdx *c, t_point p2)
{
	c->interx = c->xend + c->gradient;
	c->yend = round_(p2.y);
	c->xend = p2.x + c->gradient * (c->yend - p2.y);
	c->ygap = fpart_(p2.y+0.5);
	c->ypxl2 = c->yend;
	c->xpxl2 = ipart_(c->xend);
}
