#include "libft.h"

int	ft_isprint(int value)
{
	if (value >= 32 && value <= 126)
	{
		return (1);
	}
	return (0);
}
