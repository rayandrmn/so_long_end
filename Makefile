# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rayderha <rayderha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 16:05:33 by rayderha          #+#    #+#              #
#    Updated: 2024/11/16 16:05:39 by rayderha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Nom de l'exécutable
NAME		=	so_long

# Compilateur et flags
CC			=	clang
FLAG		=	-Wall -Wextra -Werror -g

# Libft
LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

# MiniLibX
MLX_PATH	=	./mlx/
MLX_FILE	=	libmlx.a
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_FLAGS	=	-L $(MLX_PATH) -lmlx -lXext -lX11 -lm

# Fichiers sources
SRC_DIR		=	./core/
C_FILE		=	so_long.c ft_error.c check_map.c check_map_outils.c init_game.c on_destroy.c on_keypress.c init_perso.c
SRC			=	$(addprefix $(SRC_DIR), $(C_FILE))
OBJ			=	$(SRC:.c=.o)

# Compilation des fichiers .c en .o
.c.o:
	$(CC) $(FLAG) -I includes -I $(MLX_PATH) -c $< -o $@

# Règles Makefile
all: mlx lib $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;33m\nCOMPILING $(NAME)...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[1;32m$(NAME) created successfully!\n"

lib:
	@echo "\033[0;33m\nCOMPILING LIBFT...\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT created successfully!\n"

mlx:
	@echo "\033[0;33m\nCOMPILING MINILIBX...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMINILIBX created successfully!\n"

clean:
	@echo "\033[0;31m\nCLEANING OBJECT FILES...\n"
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@rm -f $(OBJ)
	@echo "\033[1;32mDone cleaning!\n"

fclean: clean
	@echo "\033[0;31m\nDELETING EXECUTABLES...\n"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mCleaned everything!\n"

re: fclean all

.PHONY: all lib mlx clean fclean re
