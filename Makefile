# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 19:04:54 by lmaes             #+#    #+#              #
#    Updated: 2025/04/17 19:04:56 by lmaes            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compile Options
NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L/usr/X11R6/lib -lX11 -lXext -lm

# Directories
MLX = includes/mlx/libmlx_Linux.a
LIBFT = includes/libft/libft.a
PRINTF = includes/ft_printf/libftprintf.a

#
SRC =	sources/main.c \
		sources/parser/parser.c sources/parser/parser_utils.c sources/parser/parser_conditions.c \
		sources/parser/map_info.c sources/parser/check_map.c sources/parser/map_info_utils.c \
		sources/render/render.c sources/render/load.c \
		sources/render/raycast.c sources/render/raycast2.c\
		sources/movement/movement.c sources/movement/movement2.c \
		sources/movement/rotation.c \
		sources/init/utils.c sources/init/init.c \
		sources/free/free.c sources/free/free2.c \
#

BSRC =	sources_bonus/main_bonus.c \
		sources_bonus/parser/parser_bonus.c sources_bonus/parser/parser_utils_bonus.c sources_bonus/parser/parser_conditions_bonus.c \
		sources_bonus/parser/map_info_bonus.c sources_bonus/parser/check_map_bonus.c sources_bonus/parser/map_info_utils_bonus.c \
		sources_bonus/render/render_bonus.c sources_bonus/render/load_bonus.c sources_bonus/render/minimap_bonus.c \
		sources_bonus/render/raycast_bonus.c sources_bonus/render/raycast2_bonus.c \
		sources_bonus/movement/movement_bonus.c sources_bonus/movement/movement2_bonus.c \
		sources_bonus/movement/rotation_bonus.c \
		sources_bonus/init/utils_bonus.c sources_bonus/init/init_bonus.c \
		sources_bonus/free/free_bonus.c sources_bonus/free/free2_bonus.c \

# Commands
RM = rm -rf
OBJ = $(SRC:.c=.o)
B_OBJ = $(BSRC:.c=.o)

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

bonus  : $(B_OBJ) $(PRINTF) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME)_bonus $(B_OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS)

clean:
			$(RM) $(OBJ) $(B_OBJ)
			@make --silent -C includes/ft_printf clean
			@make --silent -C includes/libft clean
fclean: clean
			$(RM) $(NAME)
			$(RM) $(NAME)_bonus
			@make --silent -C includes/ft_printf fclean
			@make --silent -C includes/libft  fclean
re: fclean all
