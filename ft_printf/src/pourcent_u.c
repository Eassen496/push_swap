/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:40:23 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 17:13:23 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include <stdio.h>

static int	ft_putunbr_intlen(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	pourcent_u(unsigned int n, int fd)
{
	int		i;
	char	*num;
	int		intlen;
	int		ret;

	intlen = ft_putunbr_intlen(n);
	num = malloc((intlen + 1) * sizeof(char));
	if (!num)
		return (-1);
	num[intlen] = '\0';
	while (intlen > 0)
	{
		i = n % 10;
		n = n / 10;
		num[--intlen] = i + '0';
	}
	ret = write(fd, num, ft_stringlen(num));
	free(num);
	return (ret);
}
