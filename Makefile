NAME = RT
CC = gcc
SRC =	hooks.c\
		img.c\
		main.c\
		save_img.c\
		log.c\
		input_check.c\
		scene_parse.c\
		ft_strcsub.c

INC =	-I ./includes \
		-I ./libft/includes \
		-I ./libvec/includes \
		-I ./minilibx

LIBS = libft/libft.a libvec/libvec.a

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_FLAGS = minilibx/libmlx.a -lXext -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm
endif
FLAGS = -Wall -Werror -Wextra -g

SRC_DIR = src
OBJ_DIR = obj
OBJ			= $(SRC:.c=.o)
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: directory $(NAME)

$(NAME): libft.a libvec.a libmlx.a $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(FLAGS) $(LIBS) $(MLX_FLAGS)
	@printf "\e[33m[COMPILED] \e[32m%41s\e[39m\n" "$(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(CC) $(FLAGS) -c $^ -o $@ $(INC)

directory: $(OBJ_DIR)

$(OBJ_DIR):
	@printf "\e[33m[COMPILING] \e[32;1m%40s\n\e[39m"  "$(NAME)"
	@mkdir -p $(OBJ_DIR)

clean:
	@printf "\e[31m %30s \e[39m\n" "[CLEANING $(NAME)]" 
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@make -C libvec fclean

re: fclean all

libft.a: libft
	@make -C libft

libvec.a: libvec
	@make -C libvec

libmlx.a: minilibx
	make -C minilibx
minilibx:
	@git clone https://github.com/Rubzy0422/minilibx.git

libft:
	@git clone https://github.com/rubzy0422/libft.git

libvec:
	@git clone https://github.com/rubzy0422/libvec.git

destroy: fclean
	rm -rf libvec
	rm -rf libft
	rm -rf *.bmp
	rm -rf minilibx

.PHONY: clean all re fclean directory
