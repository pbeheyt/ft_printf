# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 15:08:45 by pbeheyt           #+#    #+#              #
#    Updated: 2022/05/21 02:15:15 by pbeheyt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIBNAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS =	./ft_printf.c \
	    ./print_nb.c \
		./print_str.c

OBJS = ${SRCS:.c=.o}


all : EXEC

EXEC : $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)

.o : .c
	$(CC) $(CFLAGS) -c $(SRCS) -o $@ -I ./

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(LIBNAME) 

re : fclean all 

.PHONY : all clean fclean re