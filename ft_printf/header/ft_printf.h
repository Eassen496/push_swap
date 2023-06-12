/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:26:20 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 17:20:31 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		pourcent_c(char c, int fd);
int		pourcent_d(int n);
int		pourcent_s(char *s, int fd);
int		pourcent_x_up(unsigned int nbr, int fd);
int		pourcent_x_min(unsigned int nbr, int fd);
int		pourcent_u(unsigned int n, int fd);
size_t	ft_stringlen(char *str);
int		ft_printf(const char *main, ...);
int		pourcent_p(unsigned long long int nbr, int fd);

#endif
