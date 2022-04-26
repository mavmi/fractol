#include "libft.h"

int	ft_tolower(int value)
{
	if (value >= 65 && value <= 90)
	{
		return (value + 32);
	}
	return (value);
}
