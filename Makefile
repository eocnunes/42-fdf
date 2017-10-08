# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/06 21:27:58 by enunes            #+#    #+#              #
#    Updated: 2017/10/07 21:01:22 by enunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror -g

SRC_FILES = fdf.c \
			parser.c \
			calculate.c \
			draw.c \
			screen.c \
			tools.c	\
			keys.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
MLX_DIR = ./mlx/
LIBFT_DIR = ./libft/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
MLX = $(addprefix $(MLX_DIR), libmlx.a)
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LINK = -L $(MLX_DIR) -L $(LIBFT_DIR) \
				-lmlx -lft -framework OpenGL -framework AppKit

all: obj $(LIBFT) $(MLX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(CFLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
	@echo -n ██████

$(LIBFT):
	@echo "\033[32mCompiling libft..."
	@make -C $(LIBFT_DIR)
	@echo "\033[1;4;32mlibft created.\033[0m"

$(MLX):
	@echo "\033[32mCompiling mlx...\033[0m"
	@make -C $(MLX_DIR)
	@echo "\033[1;4;32mmlx created.\033[0m"
	@echo  "\033[32mCompiling fdf..."

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(OBJ) $(LINK) -lm -o $(NAME)
	@echo "\033[1;4;32m\n$(NAME) Created.\033[0m"

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "\033[1;4;31OObjects removed!\033[0m"

fclean: clean
	@echo "\033[31RRemoving fdf...\033[0m"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[1;4;31m$(NAME) removed!\033[0m"

re: fclean all

.PHONY: clean fclean all re
