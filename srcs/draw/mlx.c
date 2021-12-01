#include "fdf.h"

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = mlx->addr + (y * mlx->size_line + x * (mlx->bpp / 8));
		if (*(unsigned int*)dst != 0)
			return;
		*(unsigned int*)dst = color;
	}
}
