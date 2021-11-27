#include "fdf.h"
#include <stdlib.h>

int cross_hook(t_map *map)
{
	free_split(map->map);
	exit(0);
}

int key_down_hook(int key, t_keys *keys)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		keys->w = 1;
	if (key == 0)
		keys->a = 1;
	if (key == 1)
		keys->s = 1;
	if (key == 2)
		keys->d = 1;
	if (key == 123)
		keys->left = 1;
	if (key == 124)
		keys->right = 1;
	if (key == 126)
		keys->up = 1;
	if (key == 125)
		keys->down = 1;
	return (0);
}

int key_up_hook(int key, t_keys *keys)
{
	if (key == 53)
		keys->esc = 0;
	if (key == 13)
		keys->w = 0;
	if (key == 0)
		keys->a = 0;
	if (key == 1)
		keys->s = 0;
	if (key == 2)
		keys->d = 0;
	if (key == 123)
		keys->left = 0;
	if (key == 124)
		keys->right = 0;
	if (key == 126)
		keys->up = 0;
	if (key == 125)
		keys->down = 0;
	return (0);
}
