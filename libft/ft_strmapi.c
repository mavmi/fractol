#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	new_iter;
	char			*str;

	if (!s)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	new_iter = 0;
	while (s[new_iter])
	{
		str[new_iter] = (*f)(new_iter, s[new_iter]);
		new_iter++;
	}
	str[new_iter] = '\0';
	return (str);
}
