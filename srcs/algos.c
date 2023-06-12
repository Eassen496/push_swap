/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:12 by ale-roux          #+#    #+#             */
/*   Updated: 2023/06/12 02:38:32 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	swap_zero_tob(t_list **heap_a, \
	t_list **heap_b, int cpt, t_list *tmp)
{
	while ((*heap_a)->next && tmp != (*heap_a)->next)
	{
		if ((is_sorted(*heap_a) && rev_is_sorted(*heap_b)))
			return ;
		if (!(((*heap_a)->index >> cpt) & 1))
			push(heap_a, heap_b, "pb\n");
		else
		{
			if (!tmp)
				tmp = (*heap_a);
			rotate(heap_a, "ra\n");
		}
	}
	if (!(((*heap_a)->index >> cpt) & 1))
		push(heap_a, heap_b, "pb\n");
	else
		rotate(heap_a, "ra\n");
}

static void	swap_one_toa(t_list **heap_a, \
	t_list **heap_b, int cpt, t_list	*tmp)
{
	if (!*heap_b)
		return ;
	while ((*heap_b)->next && tmp != (*heap_b)->next)
	{
		if ((is_sorted(*heap_a) && rev_is_sorted(*heap_b)))
			return ;
		if ((((*heap_b)->index >> cpt) & 1))
			push(heap_b, heap_a, "pa\n");
		else
		{
			if (!tmp)
				tmp = (*heap_b);
			rotate(heap_b, "rb\n");
		}
	}
	if ((((*heap_b)->index >> cpt) & 1))
		push(heap_b, heap_a, "pa\n");
	else
		rotate(heap_b, "rb\n");
}

void	pseudo_radix(t_list **heap_a, t_list **heap_b)
{
	int		cpt;
	int		size;

	size = bit_max(*heap_a);
	cpt = 0;
	while (cpt < size || !(is_sorted(*heap_a) && rev_is_sorted(*heap_b)))
	{
		if (is_zero(*heap_a, cpt))
			swap_zero_tob(heap_a, heap_b, cpt, NULL);
		cpt++;
		if (is_one(*heap_b, cpt))
			swap_one_toa(heap_a, heap_b, cpt, NULL);
	}
	while (*heap_b)
		push(heap_b, heap_a, "pa\n");
}

void	algo_trois(t_list **heap)
{
	if ((*heap)->index > (*heap)->next->index)
	{
		if ((*heap)->index > (*heap)->next->next->index
			&& (*heap)->next->index < (*heap)->next->next->index)
			rotate(heap, "ra\n");
		else if ((*heap)->next->index > (*heap)->next->next->index)
		{
			swap(heap, "sa\n");
			rev_rotate(heap, "rra\n");
		}
		else
			swap(heap, "sa\n");
	}
	else
	{
		if ((*heap)->index > (*heap)->next->next->index)
			rev_rotate(heap, "rra\n");
		else if ((*heap)->next->index > (*heap)->next->next->index)
		{
			rev_rotate(heap, "rra\n");
			swap(heap, "sa\n");
		}
	}
}

