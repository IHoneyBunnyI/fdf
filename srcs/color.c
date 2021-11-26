#include "fdf.h"

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
