#include "fdf.h"

int mouse_down_hook(int button, int x, int y, void *keys_old)
{
	t_keys *keys;

	keys = keys_old;
	(void)x;
	(void)y;
	(void)keys;
	printf("%d\n", button);
	if (button == 5)
		keys->mouse_zoom = 1;
	if (button == 4)
		keys->mouse_zoom = -1;
	return (1);
}

int mouse_up_hook(int button, int x, int y, void *keys_old)
{
	t_keys *keys;

	keys = keys_old;
	(void)x;
	(void)y;
	(void)keys;
	printf("AA%d\n", button);
	return (1);
}
