#ifndef FDF_H
#define FDF_H 

#define ERROR -1

typedef struct mlx
{
	void *mlx_ptr;
}	t_mlx;

char	**ft_split(char const *s, char c);
int			ft_strlen(char *s);

#endif
