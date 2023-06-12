/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:12 by ale-roux          #+#    #+#             */
/*   Updated: 2023/06/12 02:39:56 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_sorted(t_list *heap)
{
	if (!heap)
		return (1);
	while (heap->next)
	{
		if (heap->content > heap->next->content)
			return (0);
		heap = heap->next;
	}
	return (1);
}

int	rev_is_sorted(t_list *heap)
{
	if (!heap)
		return (1);
	while (heap->next)
	{
		if (heap->content < heap->next->content)
			return (0);
		heap = heap->next;
	}
	return (1);
}

int	is_zero(t_list *heap, int cpt)
{
	while (heap)
	{
		if (!((heap->index >> cpt) & 1))
			return (1);
		heap = heap->next;
	}
	return (0);
}

int	is_one(t_list *heap, int cpt)
{
	while (heap)
	{
		if (((heap->index >> cpt) & 1))
			return (1);
		heap = heap->next;
	}
	return (0);
}

int	bit_max(t_list *heap)
{
	int	max;
	int	cpt;
	int	rd;

	max = 0;
	while (heap)
	{
		if (heap->index > max)
			max = heap->index;
		heap = heap->next;
	}
	cpt = 0;
	rd = 1;
	while (max > 0)
	{
		max -= rd;
		cpt++;
		rd = (rd * 2);
	}
	return (cpt);
}
