#include "libft.h"

int	ft_toupper(int value)
{
	if (value >= 97 && value <= 122)
	{
		return (value - 32);
	}
	return (value);
}
