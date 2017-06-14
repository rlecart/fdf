# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 00:43:30 by rlecart           #+#    #+#              #
#    Updated: 2017/04/22 00:48:56 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
FILE		=	main.c \
				rec_map.c \
				verif.c \
				fdf.c \
				hook.c \
				print.c \
				drawline.c
SRC			=	$(addprefix src/,$(FILE)) libft/libft.a minilibx_macos/libmlx.a
OBJ			=	$(FILE:.c=.o)
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
MLXF		=	-framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C minilibx_macos
	make -C libft
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(MLXF)

%.o: %.c
	$(CC) -c $< $(FLAGS)

clean:
	make -C minilibx_macos clean
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
