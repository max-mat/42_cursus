# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 10:35:09 by mmatsego          #+#    #+#              #
#    Updated: 2021/02/24 15:55:27 by mmatsego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -I Add the directory dir to the list of directories to be searched for header files
# -L Searches the library when linking
# make -C flag makes you go to the appropriate path and do the asked command
# %.o: %.c - "to build a file named <something>.o, which depends on <something.c>"
# -o $@ - name of the target of the rule
#  $< - the first prerequisite of the rule (gcc -c -o $@ $< = gcc -c -o foo.o foo.c)
#  $^ - all prerequisites of the rule

NAME = cub3D

LIBFT_PATH = ./libft

MINILIBX_PATH = ./minilibx

SRCS = ./srcs/main.c \
	   ./srcs/mlx_window.c \
	   ./srcs/mlx_events.c \
	   ./srcs/player.c \

OBJS = $(SRCS:.c=.o)

INCLUDE = cube3D.h

CC = gcc

FLAGS = -O3 -Wall -Werror -Wextra

MLXFLAGS = -I ./minilibx -L ./minilibx -lmlx -framework OpenGL -framework Appkit

LIBFLAGS = -I ./libft -L ./libft ./libft/*.c 

all: libft_make minilibx_make $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(MLXFLAGS) $(LIBFLAGS) libft.a libmlx.a -I./ $(OBJS) -o $@

#%.o: %.c
#		gcc -c -o $@ $<

clean: libft_clean minilibx_clean
	rm -f $(OBJS)

fclean: libft_fclean clean
	rm -f $(NAME)

re: fclean all

# Or $(MAKE) -C libft to compile libft.a
libft_make:
		make -C $(LIBFT_PATH) all
		cp ./libft/libft.a libft.a

libft_clean:
		make -C $(LIBFT_PATH) clean

libft_fclean:
		make -C $(LIBFT_PATH) fclean
		rm -f libft.a

minilibx_make:
		make -C $(MINILIBX_PATH) all
		cp ./minilibx/libmlx.a libmlx.a

minilibx_clean:
		make -C $(MINILIBX_PATH) clean
		rm -f libmlx.a

.PHONY:	all clean fclean re
