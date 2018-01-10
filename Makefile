# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drosa-ta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 12:18:38 by drosa-ta          #+#    #+#              #
#    Updated: 2017/01/29 17:05:19 by drosa-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calc
SRCS = main.c ft_atoi.c ft_itoa.c ft_putchar.c ft_putnbr.c

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) -Wall -Werror -Wextra $(SRCS) 

clean:
	@/bin/rm -f

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
