#include "fdf.h"

void	init_map_mlx_keys(t_fdf *fdf, t_map **map, t_mlx **mlx, t_keys **keys)
{
	*map = fdf->map;
	*mlx = fdf->mlx;
	*keys = fdf->keys;
}

void	fill_image(t_mlx *mlx)
{
	int	size;

	size = WIDTH * HEIGHT * (mlx->bpp / 8);
	while (size--)
		mlx->addr[size] = 0;
}
