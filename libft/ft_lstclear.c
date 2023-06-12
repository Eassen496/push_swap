/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:00:31 by ale-roux          #+#    #+#             */
/*   Updated: 2023/06/12 23:00:32 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
