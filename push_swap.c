/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:39:27 by ale-roux          #+#    #+#             */
/*   Updated: 2022/12/25 12:55:09 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_swap_handler(char *argv, int ismalloc)
{


}

int create_args(int argc, char **argv)
{
    int i;
    char *arg;

    i = 1;
    arg = ft_calloc(1 * sizeof(char));
    if (!arg)
        return (1);
    while (i < argc - 1)
    {
        arg = ft_strjoin_free(arg, argv[i]);
        arg = ft_strjoin_free(arg, " ");
        i++;
    }
    arg = ft_strjoin_free(arg, argv[i]);
    push_swap_handler(arg, 1);
    return (0);
}

int print_error()
{
    ft_printf("Error");
    return (1);
}

int main(int argc, char **argv)
{
    int ret;

    ret = 0;
    if (argc == 2)
    {
        ret = push_swap_handler(argv[1], 0);
    }
    else if (argc == 1)
        ret = print_error();
    else
    {
        ret = create_args(argc, argv);
    }
    return (ret);
}