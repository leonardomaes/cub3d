/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:49:40 by lmaes             #+#    #+#             */
/*   Updated: 2025/02/27 12:49:43 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/************************************************/
/*					Includes					*/
/************************************************/

# include "mlx/mlx_int.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


/***********************************************/
/*					Defines						*/
/***********************************************/

// WINDOW SETTINGS
# define WINDOW_WIGTH 1280
# define WINDOW_HEIGHT 720

// Colors
# define RED_PIXEL 0xFF0000
# define BLUE_PIXEL 0x0000FF
# define GREEN_PIXEL 0x00FF00
# define WHITE_PIXEL 0xFFFFFF

/***********************************************/
/*					Structs						*/
/***********************************************/

typedef struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
}				t_mlx;

typedef	struct s_texture
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_color;
	char	*ceiling_color;
	unsigned int	floor;
	unsigned int	ceiling;
}				t_texture;

typedef struct s_map
{
	char		**layout;		// info lido do file
	int			width;
	int			height;
	char		**map;
	t_texture	*texture;	// info das texturas
}				t_map;

typedef struct s_cub
{
	char		*filename;
	t_map		*map;
	t_mlx		*mlx;
}				t_cub;

/***********************************************/
/*				Declarations					*/
/***********************************************/

// MAIN
t_cub			*game(void);

// FREE
void			clear_mlx(t_mlx *mlx);
void			clear_map(void);
void			clear_all(void);
int				kill_all(void);
void			ft_exit(char *msg, int exit_code);
void			free_split(char **data);

// UTILS
int				check_key(int keysym);
void			init_game(t_cub	*cub, const char *filename);
void			init_mlx(t_cub *cub, const char *filename);
void			setup_hook(void);

// Parser
int				file_check(void);
void			read_map(void);
char			**read_lines(int lines);
int				count_lines(void);

// Parser Conditions
void			parse_map(t_map *map, char	**content);
int				check_textures(t_map *map, char **content, int *i);
int				is_map(char	*line);
int				is_player(char c);
int				is_texture(char *str);
int				is_floor(char *str);

// Parser Utils
int				is_player(char c);
int				have_textures(t_texture *t);
int				is_map(char	*line);
int				check_top_bottom(char *line);



// Map info
int				get_textures(t_map *map, char *line, int *i);
int				get_floor(t_map *map, char *line, int *i);

// Map info utils
unsigned int	rgb_to_hex(int r, int g, int b);
int				get_hexa_color(t_map *map, char *fc);

// Utils
int				check_key(int keysym);
void			init_mlx(t_cub *cub, const char *filename);
void			init_game(t_cub	*cub, const char *filename);
void			setup_hook(void);



// Trash
void			print_map(void);

#endif