#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 16:32:36 by erli              #+#    #+#              #
#    Updated: 2018/11/12 11:10:29 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	test_gnl

SRCS	=	get_next_line.c		\
			main.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAG	=	-Wall -Werror -Wextra

INCL	=	-I libft/includes/

LIB		=	libft/ -lft


all		:	$(NAME)

$(NAME)	:	$(OBJS) get_next_line.h
			$(CC) -o $(NAME) $(OBJS) $(CFLAG) $(INCL) -L $(LIB)

%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAG) $(INCL)

clean	:
			rm -f *.o

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

clsav	:
			rm -f *~
