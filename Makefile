# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 01:42:35 by alopez-g          #+#    #+#              #
#    Updated: 2023/05/30 16:01:17 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

PROJECT_DIR	=	.
#----- HEADER -----
H_DIR	=	$(PROJECT_DIR)/include
H		=	$(wildcard $(H_DIR)/**/*.h)
#----- SRC ----
SRC_DIR	=	$(PROJECT_DIR)/src
SRC		=	$(wildcard $(SRC_DIR)/*.c) \
			$(wildcard $(SRC_DIR)/**/*.c)
#----- OBJ -----
OBJ_DIR	=	$(PROJECT_DIR)/obj
OBJ		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

#----- MLX -----
MLX_LIB		=	mlx
MLX_LIB_DIR	=	$(PROJECT_DIR)/libs/mlx
MLX_DIR		=	$(PROJECT_DIR)/libs/mlx
MLX_H_DIR	=	$(MLX_DIR)/include
#----- LIBFT -----
LIBFT_LIB		=	ft
LIBFT_LIB_DIR	=	$(PROJECT_DIR)/libs/libft
LIBFT_DIR		=	$(PROJECT_DIR)/libs/libft
LIBFT_H_DIR		=	$(LIBFT_DIR)/include

#----- FLAGS -----
CC			=	gcc
H_FLAGS		=	-I$(H_DIR) -I$(MLX_H_DIR) -I$(LIBFT_H_DIR)
C_FLAGS		=	-c -Wall -Wextra -Werror
LIB_FLAGS	=	-framework OpenGL -framework AppKit \
				-L$(MLX_LIB_DIR) -l$(MLX_LIB) \
				-L$(LIBFT_LIB_DIR) -l$(LIBFT_LIB)

#----- RULES
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir $(dir $(OBJ))

$(NAME): $(OBJ)
	@make -s -C ${MLX_DIR}
	@make -s -C ${LIBFT_DIR}
	$(CC) $(LIB_FLAGS) $(OBJ) -o $@

clean:
	@make -s -C $(MLX_DIR) clean
	@make -s -C ${LIBFT_DIR} clean
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	@make -s -C $(MLX_DIR) fclean
	@make -s -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

n:
	norminette

#----- IMPICIT RULES -----
$(addprefix $(OBJ_DIR)/, %.o):	$(addprefix $(SRC_DIR)/, %.c) $(H)
	$(CC) $(H_FLAGS) $(C_FLAGS) $< -o $@
.PHONY: clean fclean re all

#----- UTILS -----
RED				=	\033[0;31m
CYAN			=	\033[0;36m
GREEN 			=	\033[1;32m
YELLOW 			=	\033[1;33m
NC 				=	\033[0m
