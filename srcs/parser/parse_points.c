#include "fdf.h"
#include <stdlib.h>

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

	i = 0;
	while (s[i] != ',')
		i++;
	p = &(s[++i]);
	color = ft_convert_color(p);
	return color;
}

#include <math.h>
t_point **parse_points(t_map *map)
{
	t_point **points;
	int y;
	int x;
	char **split;

	points = malloc(sizeof(t_point *) * (map->height_map + 1));
	points[map->height_map] = 0;
	y = -1;
	while (++y < map->height_map)
		points[y] = malloc(sizeof(t_point) * (map->width_map + 1));
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		/*printf("%s\n", map->map[i]);*/
		split = ft_split(map->map[y], ' ');
		while (split[++x])
		{
			if (find_color(split[x]))
				points[y][x].color = get_color_from_map(split[x]);
			else
				points[y][x].color = make_color(255, 255, 255);

			//without z
			/*points[y][x].z = ft_atoi(split[x]);*/
			/*points[y][x].x = (x - y) * 30 + WIDTH / 2;*/
			/*points[y][x].y =  (x + y) * 15  + HEIGHT / 3;*/

			//non izometric
			/*points[i][x].x = x * 30;*/
			/*points[i][x].y =  i * 30;*/
			/*points[i][x].z = ft_atoi(split[x]);*/

			//with z
			points[y][x].z = ft_atoi(split[x]);
			points[y][x].x = (x - y) * 30 + WIDTH / 2;
			points[y][x].y =  ((x + y) - points[y][x].z) * 15  + HEIGHT / 3;
		}
	}
	return points;
}
