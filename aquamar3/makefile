# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquamar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 20:34:04 by aquamar           #+#    #+#              #
#    Updated: 2020/02/06 00:59:18 by aquamar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = *.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRCS)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	echo $(NAME) was Created

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
bonus:
	echo"null"
re: fclean all
