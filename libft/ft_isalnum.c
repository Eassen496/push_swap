/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:26:23 by ale-roux          #+#    #+#             */
/*   Updated: 2022/10/31 11:29:16 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else if ((c >= 65) && (c <= 90))
		return (1);
	else if ((c >= 97) && (c <= 122))
		return (1);
	else
		return (0);
}