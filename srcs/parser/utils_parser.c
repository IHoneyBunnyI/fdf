#include "fdf.h"
#include <limits.h>

int is_num_or_minus(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	if (c == '-')
		return 1;
	return 0;
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

int	ft_check_hex(char n)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	while (base[i])
	{
		if (n == ft_toupper(base[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_convert_color(char *s)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] != '0' && !(s[i + 1] == 'x' || s[i + 1] == 'X'))
		return (num);
	i += 2;
	while (ft_check_hex(s[i]) >= 0)
	{
		num = num * 16 + ft_check_hex(s[i]);
		i++;
	}
	return (num);
}

int		ft_atoi(const char *str)
{
	int		minus;
	long	result;

	minus = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > INT_MAX && minus == 1)
			return (-1);
		if (result > (long)INT_MAX + 1 && minus == -1)
			return (-1);
		result = (result * 10) + *str - '0';
		str++;
	}
	return (result * minus);
}

