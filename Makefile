# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 18:47:01 by rda-cunh          #+#    #+#              #
#    Updated: 2025/04/16 18:52:29 by rda-cunh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile Options
NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L/usr/X11R6/lib -lX11 -lXext -lm

# Directories
MLX = includes/mlx/libmlx_Linux.a
LIBFT = includes/libft/libft.a
PRINTF = includes/ft_printf/libftprintf.a

# Sources
SRC =	sources/main.c \
		sources/init/init.c \
		sources/init/utils.c \
		sources/parser/parser.c \
		sources/parser/parser_conditions.c \
		sources/parser/parser_utils.c 
		sources/parser/map_info.c \
		sources/parser/check_map.c \
		sources/parser/map_info_utils.c \
		sources/movement/movement.c \
		sources/movement/movement2.c \
		sources/movement/rotation.c \
		sources/render/render.c \
		sources/render/load.c \
		sources/render/minimap.c \
		sources/render/raycast.c \
		sources/exit_free\free.c \
		sources/exit_free\free2.c \
		sources/exit_free\trash.c \

# Commands
RM = rm -rf
OBJ = $(SRC:.c=.o)

# Rules
all: $(NAME)

%.o : %.c
			$(CC) $(CFLAGS) -c $*.c -o $*.o

$(LIBFT):
			@make --silent -C includes/libft	

$(PRINTF):
			@make --silent -C includes/ft_printf

$(MLX):
			make --silent -C includes/mlx

$(NAME) : $(OBJ) $(PRINTF) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS)

clean:
			$(RM) $(OBJ)
			@make --silent -C includes/ft_printf clean
			@make --silent -C includes/libft clean
fclean: clean
			$(RM) $(NAME)
			@make --silent -C includes/ft_printf fclean
			@make --silent -C includes/libft  fclean
re: fclean all
