#ifndef FDF_H
#define FDF_H 
#include <stdio.h> //for size_t

#define ERROR -1
#define WIDTH 1280
#define HEIGHT 720
#define W_RECT 100

typedef struct rgb_color
{
	int red;
	int green;
	int blue;
}	t_rgb_color;

typedef struct mlx
{
	void *ptr;
	void *win;
	void *img;
	char *addr;
	int bpp;
	int size_line;
	int endian;
}	t_mlx;

typedef struct map
{
	char **map;
	int width_map;
	int height_map;
}	t_map;

typedef struct keys
{
	int esc;
	int w;
	int a;
	int s;
	int d;
	int left;
	int right;
	int up;
	int down;
}	t_keys;

typedef struct point
{
	int x;
	int y;
	int z;
	int color;
}	t_point;

typedef struct fdf
{
	t_mlx *mlx;
	t_map *map;
	t_keys *keys;
	t_point **points;
	int pos_x;
	int pos_y;
}	t_fdf;

char	**ft_split(char const *s, char c);
int			ft_strlen(char *s);
char **malloc_bzero(size_t count);
int error(char *s);
int size(char **splitted);
void free_split(char **map);
int cross_hook(t_map *map);
int key_down_hook(int key, t_keys *keys);
int key_up_hook(int key, t_keys *keys);
int draw(t_fdf *fdf, t_mlx *mlx);
void	pixel_put(t_mlx *mlx, int x, int y, int color);
int		make_color(int r, int g, int b);
void draw_line_bresenham(t_mlx *mlx, t_point p0, t_point p1);
void draw_line_xiaolin_wu(t_mlx *mlx, t_point p1, t_point p2);
int	get_color(t_point current, t_point start, t_point end, t_point delta);
//char** parse_map(char *map_path);
t_map parse_map(char *map_path);
void swap_(int *a, int *b);
int	get_r(int color);
int	get_g(int color);
int	get_b(int color);
void free_split(char **split);
int	get_r(int color);
int	get_g(int color);
int	get_b(int color);
t_point **parse_points(t_map *map);
int is_num_or_minus(char c);
int		ft_atoi(const char *str);
int	ft_toupper(int c);
int	ft_check_hex(char n);
int	ft_convert_color(char *s);
#endif
