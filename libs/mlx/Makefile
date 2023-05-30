#
#
#INC_DIR=/Users/al7aro/Development/42/rank02/fract-ol/src/mlx/includes
#SRC_DIR=/Users/al7aro/Development/42/rank02/fract-ol/src/mlx/src
#
INC_DIR=include
SRC_DIR=src

NOM=libmlx.a
SRC= $(SRC_DIR)/mlx_shaders.c	$(SRC_DIR)/mlx_new_window.m \
     $(SRC_DIR)/mlx_init_loop.m	$(SRC_DIR)/mlx_new_image.m \
     $(SRC_DIR)/mlx_xpm.c	$(SRC_DIR)/mlx_int_str_to_wordtab.c
SRC+= $(SRC_DIR)/mlx_png.c $(SRC_DIR)/mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+= -w -I $(INC_DIR) -O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -rc $(NOM) $(OBJ)
	@ar -s $(NOM)

clean:
	@rm -f $(OBJ) *~
	@rm -f mlx_app

fclean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
re: clean all
