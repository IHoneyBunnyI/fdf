#include "fdf.h"
#include <stdlib.h>

int cross_hook(t_map *map)
{
	free_split(map->map);
	exit(0);
}

int key_down_hook(int key, t_keys *keys)
{
	printf("%d\n", key);
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
	if (key == 27)
		keys->minus = 1;
	if (key == 24)
		keys->plus = 1;
	if (key == 91)
		keys->alpha_minus = 1;
	if (key == 84)
		keys->alpha_plus= 1;
	if (key == 86)
		keys->beta_minus = 1;
	if (key == 88)
		keys->beta_plus= 1;
	if (key == 89)
		keys->gamma_minus = 1;
	if (key == 92)
		keys->gamma_plus= 1;
	if (key == 83)
		keys->gamma_minus = 1;
	if (key == 85)
		keys->gamma_plus= 1;
	if (key == 34 || key == 87)
		keys->is_isometric = 1;
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
	if (key == 27)
		keys->minus = 0;
	if (key == 24)
		keys->plus = 0;
	if (key == 91)
		keys->alpha_minus= 0;
	if (key == 84)
		keys->alpha_plus = 0;
	if (key == 86)
		keys->beta_minus = 0;
	if (key == 88)
		keys->beta_plus= 0;
	if (key == 89)
		keys->gamma_minus = 0;
	if (key == 92)
		keys->gamma_plus= 0;
	if (key == 83)
		keys->gamma_minus = 0;
	if (key == 85)
		keys->gamma_plus= 0;
	if (key == 34 || key == 87)
		keys->is_isometric = 0;
	return (0);
}
