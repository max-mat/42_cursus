# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 10:34:10 by mmatsego          #+#    #+#              #
#    Updated: 2021/02/01 13:35:02 by mmatsego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ./src/*.c ./libft/*.c

OBJ		= $(SRC:.c=.o)
FLAGS	= gcc -c -Wall -Wextra -Werror
HEADER	= includes/

all: $(NAME)

$(NAME):
	$(FLAGS) -c -I$(HEADER) -I ./libft $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
