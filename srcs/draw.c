#include "fdf.h"
#include "mlx.h"

void init_map_mlx_keys(t_fdf *fdf, t_map **map, t_mlx **mlx, t_keys **keys)
{
	*map = fdf->map;
	*mlx = fdf->mlx;
	*keys = fdf->keys;
}

void fill_image(t_mlx *mlx)
{
	int x;
	int y;
	int color;

	x = 0;
	y = 0;
	color = rgb_make(0, 101, 200, 120);
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			pixel_put(mlx, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

int draw(t_fdf *fdf, t_mlx *mlx)
{
	(void)fdf;
	/*t_map *map;*/
	/*t_mlx *mlx;*/
	/*t_keys *keys;*/

	/*init_map_mlx_keys(fdf, &map, &mlx, &keys);*/
	/*fill_image(mlx);*/

	/*mlx->endian = 0;*/
	for (int i = 0; i < 100; i++)
		pixel_put(mlx, i, i, 255);
	/*mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);*/
	/*for (int i = 0; map->map[i]; i++)*/
		/*printf("%d) %s\n", i, map->map[i]);*/
	return 0;
}
