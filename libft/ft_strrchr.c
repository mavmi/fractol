#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;
	char	*ptr;

	counter = 0;
	ptr = (char *)s;
	while (*(ptr++))
	{
		counter++;
	}
	ptr = (char *)s;
	while (counter >= 0)
	{
		if (ptr[counter] == (char)c)
		{
			return (ptr + counter);
		}
		counter--;
	}
	return (NULL);
}
