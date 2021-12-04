#include "fdf.h"

int mouse_down_hook(int button, int x, int y, void *keys_old)
{
	t_keys *keys;

	keys = keys_old;
	(void)x;
	(void)y;
	(void)keys;
	/*printf("%d\n", button);*/
	if (button == 1)
		keys->left_mouse = 1;
	if (button == 2)
		keys->right_mouse= 1;
	if (button == 5)
		keys->mouse_zoom = 1;
	if (button == 4)
		keys->mouse_zoom = -1;
	return (1);
}

int mouse_up_hook(int button, int x, int y, void *keys_old)
{
	t_keys *keys;

	(void)x;
	(void)y;
	keys = keys_old;
	if (button == 1)
		keys->left_mouse = 0;
	if (button == 2)
		keys->right_mouse= 0;
	return (1);
}

int mouse_move(int x, int y, void *fdf_old)
{
	t_fdf *fdf;

	fdf = fdf_old;
	int prev_x;
	int prev_y;
	prev_x = fdf->mouse->x;
	prev_y =fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->keys->left_mouse)
	{
		fdf->camera->beta += (x - prev_x) * 0.004;
		fdf->camera->alpha += (y - prev_y) * 0.004;
	}
	if (fdf->keys->right_mouse)
	{
		fdf->camera->offset_x += (x - prev_x);
		fdf->camera->offset_y += (y - prev_y);
	}
	return (0);
}
