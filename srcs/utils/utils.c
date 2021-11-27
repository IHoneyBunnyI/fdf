#include "fdf.h"
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

static int		wlen(const char *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (len);
		if (s[i] == '\0')
			return (len);
		i++;
		len++;
	}
	return (len);
}

static int		wcount(const char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char		*get_split(const char *s, int i, char **split, int len)
{
	int		j;
	char	*line;

	if (!(line = malloc(sizeof(char) * (len + 1))))
	{
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
		return (0);
	}
	j = 0;
	while (j < len)
		line[j++] = *s++;
	line[j] = '\0';
	return (line);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		len;
	int		count;

	if (!s)
		return (0);
	count = wcount(s, c);
	if (!(split = malloc(sizeof(char *) * (count + 1))))
		return (0);
	i = -1;
	j = 0;
	while (++i < count)
	{
		while (*s == c && *s != '\0')
			s++;
		len = wlen(s, c);
		if (!(split[i] = get_split(s, i, split, len)))
			return (0);
		s += len;
	}
	split[i] = 0;
	return (split);
}
