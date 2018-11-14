#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 16:17:09 by erli              #+#    #+#              #
#    Updated: 2018/11/14 13:50:29 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libft.a

SRCS	=	ft_strtoupper.c	\
			ft_strtolower.c	\
			ft_charatpos.c	\
			ft_charrevcap.c	\
			ft_charcapifeven.c	\
			ft_printstrsplit.c	\
			ft_putmem.c		\
			ft_putlst.c		\
			ft_memdellst.c		\
			ft_printlstone.c	\
			ft_lsttoupper.c		\
			ft_lstaddlast.c	\
			ft_lstreverse.c	\
			ft_strlen.c		\
			ft_strdup.c		\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strcpy.c		\
			ft_strncpy.c	\
			ft_strcat.c		\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_strcmp.c		\
			ft_strncmp.c	\
			ft_atoi.c		\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_memalloc.c	\
			ft_memdel.c		\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_strsplit.c	\
			ft_itoa.c		\
			ft_putchar.c	\
			ft_putstr.c		\
			ft_putnbr.c		\
			ft_putendl.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstiter.c	\
			ft_lstmap.c		

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAG 	=	-Wall -Werror -Wextra 

INCL	=	-I includes


all		: $(NAME)

$(NAME)	:	$(OBJS) includes/libft.h
		ar rc $(NAME) $(OBJS)

%.o		: %.c
		$(CC) -o $@ -c $< $(CFLAG) $(INCL)

delsav	:
		rm -f *~

clean	:
		rm -f $(OBJS)

fclean	: clean 
		rm -f $(NAME)

re		: clean fclean all

reset	: delsav fclean