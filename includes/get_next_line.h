#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFFER_SIZE 16
#define R =
#define A ?
#define B :

char		*ft_strjoin(char *s1, char *s2);
int			find_n(char *cache);
char		*ft_strchr(const char *s, int c);
int			ft_strlen(char *s);
char		*ft_strdup(char *s);
int				get_next_line(int fd, char **line);

#endif
