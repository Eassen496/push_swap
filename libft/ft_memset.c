/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:11:54 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/08 09:58:43 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*str2;

	i = 0;
	str2 = b;
	while (i < len)
	{
		str2[i] = c;
		i++;
	}
	return (str2);
}
