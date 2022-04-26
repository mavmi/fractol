#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*ptr;

	counter = 0;
	ptr = (unsigned char *)s;
	while (counter < n)
	{
		if (*ptr == (unsigned char)c)
		{
			return (ptr);
		}
		ptr++;
		counter++;
	}
	return (NULL);
}
