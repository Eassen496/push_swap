# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 21:21:04 by ale-roux          #+#    #+#              #
#    Updated: 2023/06/12 22:50:07 by ale-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	  = ./srcs/algo_six.c ./srcs/algos.c ./srcs/args.c ./srcs/inst.c ./srcs/utils.c ./srcs/utils2.c
NAME	  = push_swap.a
OBJS	  =  ${SRCS:.c=.o}
LIBFT     = ./libft
PRINTF    = ./ft_printf
LIBNAME   = libft.a
PRINTNAME = libftprintf.a
EXE       = push_swap

all : ${NAME}
		make -C ${LIBFT}
		make -C ${PRINTF}
		make exec

exec: ${NAME}
	gcc -Wall -Werror -Wextra ./srcs/main.c ${NAME} ${LIBFT}/${LIBNAME} ${PRINTF}/${PRINTNAME} -o ${EXE}


.c.o	:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}


${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

clean :
		rm -f ${OBJS} exec
		rm -f ${EXE}
		make clean -C ${LIBFT}
		make clean -C ${PRINTF}

fclean : clean
		rm -f ${NAME}
		make fclean -C ${LIBFT}
		make fclean -C ${PRINTF}

re : fclean all
