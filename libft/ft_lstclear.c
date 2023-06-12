#include "libft.h"

t_list	*ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst || del)
	{
		if (*lst)
		{
			while ((*lst)->next)
			{
				tmp = (*lst)->next;
				ft_lstdelone(*lst, del);
				*lst = tmp;
			}
		}
	}
	return (NULL);
}