#include "libft.h"

void	ft_lstadd_back(t_list **lst, int content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}