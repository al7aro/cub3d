# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 01:42:35 by alopez-g          #+#    #+#              #
#    Updated: 2023/06/23 00:28:37 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

PROJECT_DIR	=	.
#----- HEADER -----
H_DIR	=	$(PROJECT_DIR)/include
H		=	${H_DIR}/color.h \
			${H_DIR}/cub3d.h \
			${H_DIR}/hook.h \
			${H_DIR}/keycodes.h \
			${H_DIR}/macro.h \
			${H_DIR}/math_cub.h \
			${H_DIR}/reader.h \
			${H_DIR}/render.h \
			${H_DIR}/scene_utils.h
#----- SRC ----
SRC_DIR	=	$(PROJECT_DIR)/src
SRC		=	${SRC_DIR}/main.c \
			${SRC_DIR}/color/color.c \
			${SRC_DIR}/draw/draw_background.c \
			${SRC_DIR}/draw/draw_circle.c \
			${SRC_DIR}/draw/draw_line.c \
			${SRC_DIR}/draw/draw_point.c \
			${SRC_DIR}/draw/draw_rect.c \
			${SRC_DIR}/error_list/error.c \
			${SRC_DIR}/error_list/error_list.c \
			${SRC_DIR}/hook/hook.c \
			${SRC_DIR}/hook/hook_exit.c \
			${SRC_DIR}/hook/hook_minimap.c \
			${SRC_DIR}/hook/hook_move.c \
			${SRC_DIR}/math/math.c \
			${SRC_DIR}/reader/reader.c \
			${SRC_DIR}/reader/reader_map_closed.c \
			${SRC_DIR}/reader/reader_read_map.c \
			${SRC_DIR}/reader/reader_read_scene.c \
			${SRC_DIR}/reader/reader_utils_check.c \
			${SRC_DIR}/reader/reader_utils_skip.c \
			${SRC_DIR}/render/horizontal_ray.c \
			${SRC_DIR}/render/ray_utils.c \
			${SRC_DIR}/render/raycast.c \
			${SRC_DIR}/render/raycast_aux.c \
			${SRC_DIR}/render/render.c \
			${SRC_DIR}/render/texture.c \
			${SRC_DIR}/render/vertical_ray.c \
			${SRC_DIR}/scene_utils/scene_utils.c
#----- OBJ -----
OBJ_DIR	=	$(PROJECT_DIR)/obj
OBJ		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

#----- LIBFT -----
LIBFT_LIB		=	ft
LIBFT_LIB_DIR	=	$(PROJECT_DIR)/libs/libft
LIBFT_DIR		=	$(PROJECT_DIR)/libs/libft
LIBFT_H_DIR		=	$(LIBFT_DIR)/include

#----- FLAGS -----
CC			=	gcc
H_FLAGS		=	-I$(H_DIR) -I$(MLX_H_DIR) -I$(LIBFT_H_DIR)
C_FLAGS		=	-c -Wall -Wextra -Werror
MLX_LIB		=	mlx
MLX_LIB_DIR	=	$(PROJECT_DIR)/libs/mlx
MLX_DIR		=	$(PROJECT_DIR)/libs/mlx
MLX_H_DIR	=	$(MLX_DIR)/include
LIB_FLAGS	=	-framework OpenGL -framework AppKit -L$(MLX_LIB_DIR) -l$(MLX_LIB) -L$(LIBFT_LIB_DIR) -l$(LIBFT_LIB)

#----- RULES
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(dir $(OBJ))

$(NAME): $(OBJ)
	@make -C ${MLX_DIR}
	@make -C ${LIBFT_DIR}
	$(CC) $(OBJ) $(LIB_FLAGS) -o $@

debug: C_FLAGS += -g -D DEBUG
debug: re

clean:
	make -C $(MLX_DIR) clean
	make -C ${LIBFT_DIR} clean
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	make -C $(MLX_DIR) fclean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

n:
	norminette ${LIBFT_LIB_DIR}/src ${LIBFT_LIB_DIR}/include ${SRC} ${H}

#----- IMPICIT RULES -----
$(addprefix $(OBJ_DIR)/, %.o):	$(addprefix $(SRC_DIR)/, %.c) $(H)
	$(CC) $(H_FLAGS) $(C_FLAGS) $< -o $@
.PHONY: clean fclean re all
