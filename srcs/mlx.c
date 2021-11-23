#include "fdf.h"

/*void	pixel_put(t_fdf *fdf, int x, int y, int color)*/
/*{*/
	/*char	*dst;*/

	/*dst = fdf->mlx->addr + (y * fdf->mlx->size_line + x * (fdf->mlx->bpp / 8));*/
	/**(unsigned int*)dst = color;*/
/*}*/

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	/*mlx->size_line = 3200;*/
	dst = mlx->addr + (y * mlx->size_line + x * (mlx->bpp / 8));
	*(unsigned int*)dst = color;
}

/*void	pixel_put(t_mlx *mlx, int x, int y, int color)*/
/*{*/
	/*int i;*/

	/*if (x < WIDTH && y >= 0 && y < HEIGHT)*/
	/*{*/

		/*printf("after %d\n", mlx->size_line);*/
		/*i = (y * mlx->size_line + x * (mlx->bpp / 8));*/
		/*[>i = (x * mlx->bpp / 8) + (y * mlx->size_line);<]*/
		/*mlx->addr[i] = color;*/
	/*}*/
/*}*/

int		rgb_make(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
