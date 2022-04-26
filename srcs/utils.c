#include "../include/utils.h"

void	clean_and_exit(int exit_code, t_data *data)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
	}
	free(data);
	exit(exit_code);
}

// Compare two strings
// Return 0 if they are equal
int	cmp_strings(char *s1, char *s2)
{
	size_t	s1_len;

	if (!s1 || !s2)
		return (1);
	s1_len = ft_strlen(s1);
	if (s1_len != ft_strlen(s2))
		return (1);
	return (ft_strncmp(s1, s2, s1_len));
}

int	is_number(char *s)
{
	int		dots;

	if (!s)
		return (0);
	dots = 0;
	if (*s == '-')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			s++;
			continue ;
		}
		if (*s == '.')
			dots++;
		else
			return (0);
		if (dots > 1)
			return (0);
		s++;
	}
	return (1);
}

double	atod(char *s)
{
	int		zeros;
	char	*dot;
	double	left;
	double	right;

	if (!s)
		return (0.0);
	left = ft_atoi(s);
	dot = ft_strchr(s, '.');
	if (!dot)
		return (left);
	zeros = 0;
	dot++;
	while (*dot++ == '0')
		zeros++;
	dot -= zeros + 1;
	right = ft_atoi(dot);
	while (right >= 1)
		right = right / 10.0;
	while (zeros-- != 0)
		right = right / 10.0;
	if (s[0] == '-' && s[1] == '0')
		return ((left + right) * -1.0);
	return (left + right);
}
