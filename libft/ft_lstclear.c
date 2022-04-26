#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*next;

	if (!*lst)
		return ;
	next = *lst;
	while (next)
	{
		ptr = next;
		(*del)(ptr->content);
		next = ptr->next;
		free(ptr);
	}
	*lst = NULL;
}
