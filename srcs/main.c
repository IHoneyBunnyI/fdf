/* ************************************************************************** */
/*  💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩    */
/*  💩                    ┌┐┌┌─┐┬─┐┌┬┐  ┬┌─┐  ┌─┐┬ ┬┬┌┬┐                  💩   */
/*  💩                    ││││ │├┬┘│││  │└─┐  └─┐├─┤│ │                   💩   */
/*  💩                    ┘└┘└─┘┴└─┴ ┴  ┴└─┘  └─┘┴ ┴┴ ┴                   💩   */
/*  💩                                                                    💩   */
/*  💩                          WOOOW NORM                                💩   */
/*  💩                                                                    💩   */
/*  💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩💩   */
/*                     		               			                          */
/*      NORMINETTE LOVERS                                                     */
/*                                                                            */
/*                        ───────────────────────────────────                 */
/*                        ───────────▄▄█▀██▀█▄▄▄▄────────────                 */
/*                        ─────────▄█▀▀████▄▄█▀▀▀▀█▄▄────────                 */
/*                        ───────▄█░░░░░░░░░░░░░░░░░░█▄──────                 */
/*                        ─────▄██░░░░░░░░░░░░░░░░░░░░▀█▄────                 */
/*                        ────▄██░░░░░░░░░░░░░░░░░░░░░░░██───                 */
/*                        ────█▀░░░░░░░░▄░░░░░░░░░░▄░░░░░▀█▄─                 */
/*                        ───█▀░░░░▄▀▀▀▀░█░░░░░▄▀▀▀░▀▄░░░░░█▄                 */
/*                        ──██░░░░█░▄▀▀▄░█░░░░█░▄▀▀▄░░█░░░░██                 */
/*                        ─██░░░░░█░░▀▀░▄▀░░░░▀▄░▀▀░░▄▀░░░░░█                 */
/*                        ██▀░░░░░▀▀▀▀▀▀░░░░░░░░▀▀▀▀▀░░░░░░░█                 */
/*                        ██░░░░░░░░░░░░░▐░░░░░░░░░░░░░░░░░░█                 */
/*                        █▀░░░░░░░░░░░░░▌░░░░▌░░░░░░░░░░░░░█                 */
/*                        █░░░░░░░░░░░░░▐░▄░▄░▐░░░░░░░░░░░░░█                 */
/*                        █░░░░░░░░▐░░░░░░░░░░░░░░░░░░░░░░░░█                 */
/*                        █░░░░░░░░▌░░░░░░░░░░░░░░░░░░░░░░░██                 */
/*                        █░░░░░░░▐░░▄▀▀▀▀▀▀▀▀▄░░░░░░░░░░░░██                 */
/*                        ─█░░░░░░░▄▀▄████████▄█▄░▌░░░░░░░██─                 */
/*                        ──█░░░░░░█▄█▄▄▄▄▄▄▄▄██▀░▐░░░░░▄██──                 */
/*                        ──▀▄░░░░░░▀█▄▄▄▄▄▄▄▄▀░░░░░░░▄█▀────                 */
/*                        ────█▄░░▀▄░░░░░░░░░░░░░░░░▄█▀──────                 */
/*                        ─────█▄▄░░▀░░░░░░░░░░░░░▄█▀────────                 */
/*                        ───────▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀──────────                 */
/*                        ───────────────────────────────────                 */
/*                  ┌─┐┬ ┬┌─┐┬┌─  ┌┐┌┌─┐┬─┐┌┬┐  ┌─┐┬  ┬ ┬┌┐                   */
/*                  ├┤ │ ││  ├┴┐  ││││ │├┬┘│││  │  │  │ │├┴┐                  */
/*                  └  └─┘└─┘┴ ┴  ┘└┘└─┘┴└─┴ ┴  └─┘┴─┘└─┘└─┘                  */
/*                                                                            */
/*   By: NORM IS SHIT                         LIKE NORMINETTE                 */
/*                                                                            */
/*   Created: fjkghdkfg fdkjghdHdb by norm is Shit                            */
/*   Updated: BBBBBBBBBB 99999999 by FUCK THE NORM                            */
/*                   ┌─┐┬ ┬┌─┐┬┌─  ┌┐┌┌─┐┬─┐┌┬┐  ┌─┐┬  ┬ ┬┌┐                  */
/*                   ├┤ │ ││  ├┴┐  ││││ │├┬┘│││  │  │  │ │├┴┐                 */
/*                   └  └─┘└─┘┴ ┴  ┘└┘└─┘┴└─┴ ┴  └─┘┴─┘└─┘└─┘                 */
/*                                                                            */
/*      Ставь лайк, если ты тоже любишь норму ❤️                              */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "get_next_line.h"
#include <stdlib.h>

void	mlx_start(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "fdf");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr \
				(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
}

void	hooks(t_mlx *mlx, t_map *map, t_keys *keys, t_fdf *fdf)
{
	mlx_hook(mlx->win, 17, 0, &cross_hook, map);
	mlx_hook(mlx->win, 2, 0, &key_down_hook, keys);
	mlx_hook(mlx->win, 3, 0, &key_up_hook, keys);
	mlx_hook(mlx->win, 4, 0, mouse_down_hook, keys);
	mlx_hook(mlx->win, 5, 0, mouse_up_hook, keys);
	mlx_hook(mlx->win, 6, 0, mouse_move, fdf);
}

int	main(int ac, char **av)
{
	t_map		map;
	t_mlx		mlx;
	t_keys		keys;
	t_camera	camera;
	t_fdf		fdf;

	fdf.map = init_map(&map);
	fdf.mlx = init_mlx(&mlx);
	fdf.keys = init_keys(&keys);
	fdf.camera = init_camera(&camera);
	fdf.points = 0;
	if (ac != 2)
		return (error("\033[1;41mError arguments\033[0m"));
	map = parse_map(av[1]);
	if (!map.map)
		return (error("\033[1;41mError map\033[0m"));
	fdf.points = parse_points(&map);
	if (fdf.points == 0)
		return (0);
	mlx_start(&mlx);
	hooks(&mlx, &map, &keys, &fdf);
	mlx_loop_hook(mlx.ptr, &draw, &fdf);
	free_split(map.map);
	map.map = 0;
	mlx_loop(mlx.ptr);
}
