/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:12 by ale-roux          #+#    #+#             */
/*   Updated: 2023/06/12 02:39:22 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	print_tlist(t_list *heap)
{
	ft_printf("\n--- START ---\n");
	while (heap)
	{
		ft_printf("%d - %d | ", heap->content, heap->index);
		heap = heap->next;
	}
}

int	verif_arg(char *arg)
{
	if (ft_strncmp(arg, ft_itoa(ft_atoi(arg)), ft_strlen(arg)) != 0)
	{
		return (1);
	}
	return (0);
}

int	main_bis(int argc, char **argv, t_list *heap_a)
{
	t_list	*heap_b;

	heap_a = NULL;
	heap_a = create_list(argc, argv, NULL);
	if (heap_a == NULL)
	{
		ft_printf("error");
		return (EXIT_FAILURE);
	}
	heap_b = NULL;
	if (ft_lstsize(heap_a) == 1)
		return (verif_arg(argv[1]));
	if (ft_lstsize(heap_a) == 2)
	{
		if (heap_a->index > heap_a->next->index)
			ft_printf("sa\n");
	}
	else if (ft_lstsize(heap_a) == 3)
		algo_trois(&heap_a);
	else if (ft_lstsize(heap_a) < 6)
		algo_six(&heap_a, &heap_b);
	else
		pseudo_radix(&heap_a, &heap_b);
	return (0);
}

int	arg_error(int argc, char **argv)
{
	int i;
	int error;

	i = 1;
	error = 0;
	while ((i < argc - 1))
	{
		if (ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
			i++;
		else
		{
			error++;
			break ;
		}
	}
	i = 1;
	while ((i <= argc - 1))
	{
		if (ft_strncmp(ft_itoa(ft_atoi(argv[i])), argv[i], ft_strlen(argv[i])) == 0)
			i++;
		else
		{
			write(1, "error", 5);
			error++;
			break ;
		}
	}
	return (error);
}

int	main(int argc, char **argv)
{
	int	error;

	error = 0;
	if (argc < 2)
		return (EXIT_SUCCESS);
	error = arg_error(argc, argv);
	if (error == 0)
		main_bis(argc, argv, NULL);
	return (0);
}
