#include "fdf.h"
#include <math.h>

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
