#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counter;

	if (dst == src)
		return (dst);
	counter = 0;
	while (counter < n)
	{
		*(unsigned char *)(dst + counter) = *(unsigned char *)(src + counter);
		counter++;
	}
	return (dst);
}
