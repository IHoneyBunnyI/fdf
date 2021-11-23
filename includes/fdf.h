#ifndef FDF_H
#define FDF_H 
#include <stdio.h> //for size_t

#define ERROR -1

typedef struct mlx
{
	void *mlx_ptr;
}	t_mlx;

char	**ft_split(char const *s, char c);
int			ft_strlen(char *s);
char **malloc_bzero(size_t count);
int error(char *s);
int size(char **splitted);

#endif
