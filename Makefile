NAME = RT
CC = gcc
SRC =	hooks.c\
		img.c\
		main.c\
		save_img.c

INC =	-I ./includes \
		-I ./libft/includes \
		-I ./libvec/includes

LIBS = libft/libft.a libvec/libvec.a

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm
FLAGS = -Wall -Werror -Wextra -g

SRC_DIR = src
OBJ_DIR = obj
OBJ			= $(SRC:.c=.o)
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: directory $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) libft.a libvec.a
	@$(CC) $(OBJS) -o $(NAME) $(FLAGS) $(MLX_FLAGS) $(LIBS)
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
	@make -C libft fclean
	@make -C libvec fclean

	@rm -f $(NAME)

re: fclean all

libft.a: libft
	@make -C libft

libvec.a: libvec
	@make -C libvec

libft:
	git clone https://github.com/libft.git
libvec:
	git clone https://github.com/libvec.git

.PHONY: clean all re fclean directory
