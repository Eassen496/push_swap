/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:01:28 by ale-roux          #+#    #+#             */
/*   Updated: 2023/06/12 23:01:45 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
