#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		*(unsigned char *)(dst + counter) = *(unsigned char *)(src + counter);
		if (*(unsigned char *)(dst + counter++) == (unsigned char)c)
		{
			return (dst + counter);
		}
	}
	return (NULL);
}
