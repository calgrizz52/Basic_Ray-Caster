# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkok <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 12:19:29 by mkok              #+#    #+#              #
#    Updated: 2017/06/15 18:38:54 by mkok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3d

CC = gcc

FLAG = #-Wall -Werror -Wextra

LIBMLX =  -L mlx/ -lmlx -lm -framework OpenGL -framework AppKit

# gcc main.c -L. -lmlx -L libft/ -lft -framework OpenGL -framework AppKit
#
SRC =   ./src/main.c		\
		./src/init.c		\
		./src/calc.c		\
		./src/draw.c		\
		./src/hooks.c		\
		./src/map.c			\
		./src/move.c

OBJ = $(SRC:.c=.o)

LIBFT = -L libft/ -lft -I libft/

.PHONY:clean re all fclean

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(FLAG) -o $(NAME) $(SRC) $(LIBFT) $(LIBMLX)
	@echo "\033[33;32m$(NAME) is ready :0"

%.o:%.c
	@$(CC) $(FLAG) -o $@ -c $< -I libft/ -I.

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "\x1b[36mclean ok"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\x1b[36mfclean ok"

re: fclean all
