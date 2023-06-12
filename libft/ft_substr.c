/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:19:37 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/17 21:56:29 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	int				x;

	i = start;
	x = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) && ft_strlen(s) != 0)
		len = ft_strlen(s) - start;
	else if (ft_strlen(s) - start <= len)
		len = ft_strlen(s) - start;
	else if (ft_strlen(s) > start && len < start)
		len = len + 1 - 1;
	else if (len < start)
		len = start - len;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < (len + start) && s[i])
		str[x++] = s[i++];
	str[x] = 0;
	return (str);
}
