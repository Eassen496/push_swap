/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:40:23 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/08 10:45:45 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	int_to_char(int n, int fd)
{
	char	c;

	if (n < 10 && n >= 0)
	{
		c = 48 + n;
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n < 10 && n > -1)
		int_to_char(n, fd);
	else
	{
		if (n > 0)
		{
			i = n % 10;
			n = n / 10;
			ft_putnbr_fd(n, fd);
			int_to_char(i, fd);
		}
	}
}
