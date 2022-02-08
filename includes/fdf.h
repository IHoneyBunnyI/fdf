#ifndef FDF_H
# define FDF_H 
# include <stdio.h>

# define ERROR -1
# define WIDTH 1280
# define HEIGHT 720
# define A ?
# define B :
//#define WIDTH 2560
//#define HEIGHT 1440

typedef struct rgb_color
{
	int	red;
	int	green;
	int	blue;
}	t_rgb_color;

typedef struct map
{
	char	**map;
	int		width_map;
	int		height_map;
	int		max_z;
	int		min_z;
	int		square_size;
}	t_map;

typedef struct mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_mlx;

typedef struct keys
{
	char	esc;
	char	w;
	char	a;
	char	s;
	char	d;
	char	left;
	char	right;
	char	up;
	char	down;
	char	plus;
	char	minus;
	char	alpha_plus;
	char	alpha_minus;
	char	beta_plus;
	char	beta_minus;
	char	gamma_plus;
	char	gamma_minus;
	char	is_isometric;
	char	is_parralel;
	char	rotate;
	char	gamma_rotate;
	char	invert_color;
	char	shift;
	char	h;
	char	j;
	char	k;
	char	l;
	char	ctrl;
	char	mouse_zoom;
	char	left_mouse;
	char	right_mouse;
	char	wheel;
}	t_keys;

typedef struct point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	first_color;
}	t_point;

typedef struct s_camera
{
	float	alpha;
	float	beta;
	float	gamma;
	float	z_coefficient;
	int		offset_x;
	int		offset_y;
	float	speed_rotate;
	int		acceleration;
}	t_camera;

typedef struct s_intdx
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
}	t_intdx;

typedef struct s_xy
{
	int x;
	int y;
}	t_xy;

typedef struct fdf
{
	t_mlx		*mlx;
	t_map		*map;
	t_keys		*keys;
	t_camera	*camera;
	t_point		**points;
	int mouse_x;
	int mouse_y;
}	t_fdf;

char		**ft_split(char const *s, char c);
int			ft_strlen(char *s);
char		**malloc_bzero(size_t count);
int			error(char *s);
int			size(char **splitted);
void		free_split(char **map);
int			cross_hook(t_map *map);
int			key_down_hook(int key, t_keys *keys);
int			key_up_hook(int key, t_keys *keys);
int			draw(t_fdf *fdf, t_mlx *mlx);
void		pixel_put(t_mlx *mlx, int x, int y, int color);
int			make_color(int r, int g, int b);
void		draw_line_bresenham(t_fdf *fdf, t_point p0, t_point p1);
void		draw_line_xiaolin_wu(t_fdf *fdf, t_point p1_in, t_point p2_in);
int			get_color(t_point current, t_point start, t_point end, t_point delta);
t_map		parse_map(char *map_path);
int			get_r(int color);
int			get_g(int color);
int			get_b(int color);
void		free_split(char **split);
t_point		**parse_points(t_map *map);
int			is_num_or_minus(char c);
int			ft_atoi(const char *str);
int			ft_toupper(int c);
int			ft_check_hex(char n);
int			ft_convert_color(char *s);
void		check_keys(t_fdf *fdf, t_keys *keys);
void		rotate_z(t_point *p, double gamma);
void		rotate_y(t_point *p, double beta);
void		rotate_x(t_point *p, double alpha);
void		iso(t_fdf *fdf, t_point *p1, t_point *p2);
void		parallel(t_fdf *fdf, t_point *p1, t_point *p2);
t_point		set_point(t_fdf *fdf, t_point p);
void		rotate_x(t_point *p, double alpha);
void		rotate_y(t_point *p, double beta);
void		rotate_z(t_point *p, double gamma);
int			mouse_up_hook(int button, int x, int y, void *keys_old);
int			mouse_down_hook(int button, int x, int y, void *keys_old);
int			mouse_move(int x, int y, void *fdf_old);
int			ft_min(int a, int b);
void		init_map_mlx_keys(t_fdf *fdf, t_map **map, t_mlx **mlx, t_keys **keys);
void		fill_image(t_mlx *mlx);
t_map		*init_map(t_map *map);
t_mlx		*init_mlx(t_mlx *mlx);
t_keys		*init_keys(t_keys *keys);
t_camera	*init_camera(t_camera *camera);
#endif
