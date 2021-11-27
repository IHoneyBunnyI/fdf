#include "fdf.h"

int	get_r(int color)
{
	return (color >> 16 & 0xFF);
}

int	get_g(int color)
{
	return (color >> 8 & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}

int		color(int r, int g, int b)
{
	int t = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}

t_rgb_color	rgb_color(int r, int g, int b)
{
	t_rgb_color c;

	c.red = r;
	c.green = g;
	c.blue = b;
	return (c);
}

double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point current, t_point s, t_point e, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == e.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(s.x, e.x, current.x);
	else
		percentage = percent(s.y, e.y, current.y);
	red = get_light((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percentage);
	green = get_light((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percentage);
	blue = get_light(s.color & 0xFF, e.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
