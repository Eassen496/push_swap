/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:12 by ale-roux          #+#    #+#             */
/*   Updated: 2023/01/16 22:27:22 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static t_list	*multiples_args(char *str, t_list **lst)
{
	char	**tab;
	int		cpt;

	cpt = 0;
	tab = ft_split(str, ' ');
	while (tab[cpt])
	{
		if (!lst || !is_in(*lst, tab[cpt]))
			ft_lstadd_back(lst, ft_atoi(tab[cpt]));
		else
			return (ft_lstclear(lst, &free));
		free(tab[cpt++]);
	}
	free(tab);
	return (*lst);
}

static t_list	*sort(t_list *lst)
{
	int		s;
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
		{
			s = tmp->next->content;
			tmp->next->content = tmp->content;
			tmp->content = s;
		}
		tmp = tmp->next;
	}
	return (lst);
}

static t_list	*set_index(t_list *tried, t_list *lst)
{
	int		index;
	t_list	*save;

	index = 0;
	tried = lst_dup(lst);
	save = tried;
	while (!is_sorted(tried))
		tried = sort(tried);
	while (tried)
	{
		tried->index = index++;
		tried = tried->next;
	}
	return (update(save, lst));
}

t_list	*create_list(int ac, char **av, t_list *lst)
{
	int		cpt;

	cpt = 0;
	while (++cpt < ac)
	{
		if (!has_alpha(av[cpt]))
		{
			if (ft_strrchr(av[cpt], ' '))
			{
				if (!multiples_args(av[cpt], &lst))
					return (NULL);
			}
			else
			{
				if (!is_in(lst, av[cpt]))
					ft_lstadd_back(&lst, ft_atoi(av[cpt]));
				else
					return (ft_lstclear(&lst, &free));
			}
		}
		else
			return (NULL);
	}
	return (set_index(NULL, lst));
}
