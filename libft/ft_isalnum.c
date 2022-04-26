#include "libft.h"

int	ft_isalnum(int value)
{
	if (ft_isdigit(value) || ft_isalpha(value))
	{
		return (1);
	}
	return (0);
}
