# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/06 21:27:58 by enunes            #+#    #+#              #
#    Updated: 2017/10/06 23:22:40 by enunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

N_INC = fdf.h

N_SRCS =	fdf.c		\
			parser.c	\
			calculate.c	\
			draw.c		\
			screen.c	\

X_LFT = -L$(P_LFT) -lft
X_MLX = -L$(P_MLX) -lmlx -framework OpenGL -framework AppKit

P_SRCS = srcs/
P_OBJ = obj/
I_INC = includes
I_LFT = libft/includes
P_LFT = libft
P_MLX = minilibx

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

INC = $(addprefix -I,$(I_INC) $(I_LFT) $(P_MLX))
SRC = $(addprefix $(P_SRCS),$(N_SRCS))
OBJ = $(addprefix $(P_OBJ),$(OBJ_NAME))

OBJ_NAME = $(N_SRCS:.c=.o)

all: $(NAME)

project: clean proj

proj: $(OBJ)
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) $(X_LFT) $(X_MLX)

$(NAME): $(OBJ)
	@make -C $(P_LFT)
	@make -C $(P_MLX)
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) $(X_LFT) $(X_MLX)

$(P_OBJ)%.o: $(P_SRCS)%.c
	@mkdir -p $(P_OBJ)
	@$(CC) $(CC_FLAGS) -o $@ -c $^ $(INC)

clean:
	@make -C $(P_LFT) clean
	@rm -rf $(P_OBJ)

fclean: clean
	@make -C $(P_LFT) fclean
	@make -C $(P_MLX) clean
	@rm -f $(NAME)

re: fclean all
