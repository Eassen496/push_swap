
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	c;

	if (lst == 0)
		return (0);
	c = 0;
	while (lst->next != 0)
	{
		lst = lst->next;
		c++;
	}
	return (c + 1);
}