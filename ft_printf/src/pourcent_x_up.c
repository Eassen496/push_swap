/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent_x_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:19:00 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 17:29:05 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	putnbr_hexup_fd_len(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr > 0)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i);
}

int	pourcent_x_up(unsigned int nbr, int fd)
{
	int		j;
	char	*result;
	int		len;
	char	*base;

	base = "0123456789ABCDEF";
	len = putnbr_hexup_fd_len(nbr);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (-1);
	result[len] = '\0';
	while (len > 0)
	{
		j = nbr % 16;
		nbr = nbr / 16;
		result[--len] = base[j];
	}
	len = ft_stringlen(result);
	j = write(fd, result, len);
	free(result);
	return (j);
}
