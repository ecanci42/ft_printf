# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecanci <ecanci@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 15:22:50 by ecanci            #+#    #+#              #
#    Updated: 2022/11/23 17:57:34 by ecanci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printf_utils.c
OBJS	= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

NAME	= libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
