/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:26:59 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/08 19:03:08 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int	i;
	char			*strdst;
	char			*strsrc;

	strdst = (char *)dst;
	strsrc = (char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i != n)
	{
		strdst[i] = strsrc[i];
		i++;
	}
	return (dst);
}
