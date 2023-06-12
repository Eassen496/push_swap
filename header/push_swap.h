/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:12 by ale-roux          #+#    #+#             */
/*   Updated: 2023/01/16 22:27:22 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include "../ft_printf/header/ft_printf.h"

int		is_sorted(t_list *heap);
int		bit_max(t_list *heap);
int		is_one(t_list *heap, int cpt);
int		is_zero(t_list *heap, int cpt);
int		rev_is_sorted(t_list *heap);
int		is_sorted(t_list *heap);
int		has_alpha(char *str);
int		is_in(t_list *lst, char *str);
void	print_tlist(t_list *lst);
void	pseudo_radix(t_list **heap_a, t_list **heap_b);
void	algo_trois(t_list **heap);
void	algo_six(t_list **heap_a, t_list **heap_b);
void	rev_rotate(t_list **heap, char *inst);
void	rotate(t_list **heap, char *inst);
void	push(t_list **heap_from, t_list **heap_to, char *inst);
void	swap(t_list **heap_a, char *inst);
t_list	*create_list(int ac, char **av, t_list *lst);
t_list	*min(t_list **lst);
t_list	*create_list(int ac, char **av, t_list *lst);
t_list	*lst_dup(t_list *lst);
t_list	*update(t_list *s, t_list *t);

#endif