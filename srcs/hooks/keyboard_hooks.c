#include "fdf.h"
#include <stdlib.h>

int cross_hook(t_map *map)
{
	(void)map;
	/*free_split(map->map);*/
	/*while (1);*/
	exit(0);
}

int key_down_hook(int key, t_keys *keys)
{
	/*printf("%d\n", key);*/
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
	if (key == 89 || key == 83)
		keys->gamma_minus = 1;
	if (key == 92 || key == 85)
		keys->gamma_plus= 1;
	if (key == 34)
		keys->is_isometric = 1;
	if (key == 35)
		keys->is_parralel = 1;
	if (keys->rotate == 0 && key == 15) //запуск
		keys->rotate = 1;
	else if (keys->rotate == 1 && key == 15) //стоп
		keys->rotate = 0;
	if (keys->invert_color == 0 && key == 8)
		keys->invert_color = 1;
	if (key == 257)
		keys->shift = 1;
	if (key == 4)
		keys->h = 1;
	if (key == 37)
		keys->l = 1;
	if (key == 38)
		keys->j = 1;
	if (key == 40)
		keys->k = 1;
	if (key == 256)
		keys->ctrl = 1;
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
	if (key == 91 || key == 40)
		keys->alpha_minus= 0;
	if (key == 84 || key == 38)
		keys->alpha_plus = 0;
	if (key == 86 || key == 4)
		keys->beta_minus = 0;
	if (key == 88 || key == 37)
		keys->beta_plus= 0;
	if (key == 89 || key == 83)
		keys->gamma_minus = 0;
	if (key == 92 || key == 85)
		keys->gamma_plus= 0;
	if (key == 34)
		keys->is_isometric = 0;
	if (key == 35)
		keys->is_parralel = 0;
	if (key == 257)
		keys->shift = 0;
	if (key == 4)
		keys->h = 0;
	if (key == 37)
		keys->l = 0;
	if (key == 38)
		keys->j = 0;
	if (key == 40)
		keys->k = 0;
	if (key == 256)
		keys->ctrl = 0;
	return (0);
}
