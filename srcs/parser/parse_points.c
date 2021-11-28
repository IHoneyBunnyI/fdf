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
		points[i] = malloc(sizeof(t_point) * (map->width_map + 1));
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		/*printf("%s\n", map->map[i]);*/
		split = ft_split(map->map[i], ' ');
		while (split[++j])
		{
			if (find_color(split[j]))
				points[i][j].color = get_color_from_map(split[j]);
			else
				points[i][j].color = make_color(255, 255, 255);
			points[i][j].x = (j - i) * 30 + WIDTH / 2;
			points[i][j].y =  (j + i) * 15;
			points[i][j].z = ft_atoi(split[j]);

			/*points[i][j].x = j * 30;*/
			/*points[i][j].y =  i * 30;*/
			/*points[i][j].z = ft_atoi(split[j]);*/
		}
	}
	return points;
}
