#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			c;
	unsigned char	*d;
	unsigned char	*s;

	c = 0;
	if (dst == (void *)src)
		return (dst);
	d = (unsigned char *)(dst + len - 1);
	s = (unsigned char *)(src + len - 1);
	if (src - dst < 0)
	{
		while (len-- > 0)
		{
			*(d--) = *(s--);
		}
	}
	else
	{
		while (c < len)
		{
			*(unsigned char *)(dst + c) = *(const unsigned char *)(src + c);
			c++;
		}
	}
	return (dst);
}
