#include "libft.h"

int	ft_isascii(int value)
{
	if (value >= 0 && value <= 127)
	{
		return (1);
	}
	return (0);
}
