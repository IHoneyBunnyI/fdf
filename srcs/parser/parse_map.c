#include "fdf.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int lenth_file(char *map_path)
{
	char *line;
	int len_file;
	int fd_map;

	len_file = 0;
	line = 0;
	fd_map = 0;
	fd_map = open(map_path, O_RDONLY);
	if (fd_map == -1)
		return (ERROR);
	while (get_next_line(fd_map, &line))
	{
		len_file++;
		free(line);
	}
	free(line);
	close(fd_map);
	return (len_file);
}

void fill_map(char **map, int fd_map)
{
	char *line;
	int i;

	i = 0;
	line = 0;
	while (get_next_line(fd_map, &line))
	{
		map[i++] = ft_strdup(line);
		free(line);
	}
	free(line);
	close(fd_map);
}

int wrong_characters(char **split_str)
{
	int split;
	int i;

	split = -1;
	while (split_str[++split])
	{
		i = -1;
		while (split_str[split][++i] != ',' && split_str[split][i])
		{
			if (!is_num_or_minus(split_str[split][i]))
				return 1;
		}
	}
	return 0;
}

int check_map(t_map *map, int len_file)
{
	int i;
	int width;
	char **str_split_1;
	char **str_split_2;

	str_split_1 = ft_split(map->map[0], ' ');
	width = size(str_split_1);
	i = -1;
	while (++i < len_file)
	{
		str_split_2 = ft_split(map->map[i], ' ');
		if (width != size(str_split_2) || wrong_characters(str_split_2))
				return ERROR;
		free_split(str_split_2);
	}
	map->width_map = width;
	free_split(str_split_1);
	return 0;
}

t_map parse_map(char *map_path)
{
	t_map map;
	int fd_map;
	char *line;

	line = 0;
	map.height_map = lenth_file(map_path);
	if (map.height_map == ERROR)
	{
		map.map = 0;
		return map;
	}
	fd_map = open(map_path, O_RDONLY);
	map.map = malloc_bzero(sizeof(char *) * (map.height_map + 1));
	fill_map(map.map, fd_map);
	if (check_map(&map, map.height_map) == ERROR)
	{
		map.map = 0;
		return map;
	}
	if (map.width_map > map.height_map)
		map.square_size = WIDTH / (map.width_map * 2);
	else
		map.square_size = HEIGHT / (map.height_map * 2);
	return (map);
}

