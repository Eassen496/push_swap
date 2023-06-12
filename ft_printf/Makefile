# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 21:21:04 by ale-roux          #+#    #+#              #
#    Updated: 2022/11/15 17:24:47 by ale-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./src/pourcent_c.c ./src/pourcent_d.c ./src/pourcent_x_up.c \
		  ./src/pourcent_s.c ./src/pourcent_u.c ./src/ft_stringlen.c \
		  ft_printf.c ./src/pourcent_p.c ./src/pourcent_x_min.c
NAME	= libftprintf.a
OBJS	=  ${SRCS:.c=.o}

.c.o	:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all
