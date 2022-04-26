#include "libft.h"

int	ft_isalpha(int value)
{
	if ((value >= 65 && value <= 90) || (value >= 97 && value <= 122))
	{
		return (1);
	}
	return (0);
}
