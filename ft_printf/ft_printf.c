/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:35:20 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 17:26:54 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./header/ft_printf.h"

static int	ft_printf_handler(char c, va_list arg)
{
	int	len;

	len = -1;
	if (c == 'c')
		len = pourcent_c(va_arg(arg, int), 1);
	else if (c == 's')
		len = pourcent_s(va_arg(arg, char *), 1);
	else if (c == 'p')
		len = pourcent_p(va_arg(arg, unsigned long long), 1);
	else if (c == 'd' || c == 'i')
		len = pourcent_d(va_arg(arg, int));
	else if (c == 'u')
		len = pourcent_u(va_arg(arg, unsigned int), 1);
	else if (c == 'x')
		len = pourcent_x_min(va_arg(arg, unsigned int), 1);
	else if (c == 'X')
		len = pourcent_x_up(va_arg(arg, unsigned int), 1);
	else if (c == '%')
		len = write(1, "%", 1);
	if (len == -1)
		len = -2147483648;
	return (len);
}

int	ft_printf(const char *main, ...)
{
	int		i;
	va_list	arg;
	int		ret;

	ret = 0;
	i = 0;
	va_start(arg, main);
	while (main[i])
	{
		if (main[i] == '%')
			ret += ft_printf_handler(main[++i], arg);
		else
			ret += write(1, &main[i], 1);
		i++;
		if (ret < 0)
			return (-1);
	}
	va_end(arg);
	return (ret);
}
