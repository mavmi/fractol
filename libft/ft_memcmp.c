#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	counter = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (counter < n)
	{
		if (*ptr1 != *ptr2)
		{
			return (*ptr1 - *ptr2);
		}
		counter++;
		ptr1++;
		ptr2++;
	}
	return (0);
}
