# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 15:28:49 by mmatsego          #+#    #+#              #
#    Updated: 2021/02/05 16:54:23 by mmatsego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = gcc -c -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_itoa_base.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_numlen.c \
	  ft_putadr.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_puthex.c \
	  ft_putnbr_fd.c \
	  ft_putnbrf.c \
	  ft_putstr_fd.c \
	  ft_putstrf.c \
	  ft_putstr.c \
	  ft_putuhex.c \
	  ft_putunbr.c \
	  ft_split.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcut.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c \

OBJ = $(SRC:.c=.o)

BONUS = ft_lstadd_back.c \
	  ft_lstadd_front.c \
	  ft_lstclear.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstlast.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_lstsize.c \

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME):
		$(FLAGS) $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
		ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus
