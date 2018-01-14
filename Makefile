# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 00:20:07 by drosa-ta          #+#    #+#              #
#    Updated: 2018/01/13 14:58:44 by scamargo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calc
SRCS = main.c ft_ptr_atoi.c bignum.c add_bignum.c subtract_bignum.c mult_bignum.c errors.c

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) -Wall -Werror -Wextra  -I . -L. -lft $(SRCS) 

debug:
	@gcc -g -o $(NAME) -Wall -Werror -Wextra  -I . -L. -lft $(SRCS) 

clean:
	@/bin/rm -f

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
