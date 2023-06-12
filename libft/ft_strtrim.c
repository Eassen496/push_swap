/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:24:11 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 16:32:41 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*place(char *res, int *tab)
{
	if (!res)
		return (NULL);
	if (tab[0] > tab[1])
		return (res);
	else
		return (res);
}

static int	is_set(const char c, const char *set)
{
	int	i;

	i = 0;
	if (set)
	{
		while (set[i])
		{
			if (set[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		tab[3];

	tab[0] = 0;
	tab[2] = 0;
	if (!s1 || !set)
		return (NULL);
	if (set[0] == '\0' || s1[0] == '\0')
		return (ft_strdup(s1));
	if (s1)
	{
		tab[1] = ft_strlen(s1);
		while (is_set(s1[tab[0]], set) == 1 && s1[tab[0]])
			tab[0]++;
		while (is_set(s1[tab[1] - 1], set) == 1 && tab[1] > tab[0])
			tab[1]--;
		res = malloc(sizeof(char) * (tab[1] - tab[0] + 1));
		if (!res || tab[0] > tab[1])
			return (place(res, tab));
		while (tab[0] < tab[1])
			res[tab[2]++] = s1[tab[0]++];
		res[tab[2]] = '\0';
		return (res);
	}
	return (NULL);
}
