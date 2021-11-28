#include "fdf.h"
#include <stdlib.h>
#include <limits.h>

int		ft_atoi(const char *str)
{
	int		minus;
	long	result;

	minus = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > INT_MAX && minus == 1)
			return (-1);
		if (result > (long)INT_MAX + 1 && minus == -1)
			return (-1);
		result = (result * 10) + *str - '0';
		str++;
	}
	return (result * minus);
}

int find_color(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == ',' && s[i + 1] != 0)
			return 1;
	}
	return 0;
}

int get_color_from_map(char *s)
{
	int i;
	char *p;
	int color;

	i = -1;
	while (s[++i] != ',')
	{
		p = &(s[i]);
		color = ft_atoi(p);
	}
	return color;
}

t_point **parse_points(t_map *map)
{
	t_point **points;
	int i;
	int j;
	char **split;

	points = malloc(sizeof(t_point *) * (map->height_map + 1));
	points[map->height_map] = 0;
	i = -1;
	while (++i < map->height_map)
		points[i] = malloc(sizeof(t_point) * (map->width_map));
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		split = ft_split(map->map[i], ' ');
		while (split[++j])
		{
			if (find_color(split[j]))
				points[i][j].color = get_color_from_map(split[j]);
			else
				points[i][j].color = make_color(255, 255, 255);
			points[i][j].x = i;
			points[i][j].y = j;
			points[i][j].z = ft_atoi(split[j]);
		}
	}
	return points;
}
