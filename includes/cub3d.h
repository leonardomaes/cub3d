/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:49:40 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/23 23:44:11 by rda-cunh         ###   ########.fr       */
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
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define FOV 66.00

// Colors
# define RED_PIXEL 0xFF0000
# define BLUE_PIXEL 0x0000FF
# define GREEN_PIXEL 0x00FF00
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define GRAY_PIXEL 0xAAAAAA

// MAP SETTINGS
# define MOVE_SPEED 0.10
# define ROTATION_SPEED 5.0
# define MAP_SCALE 0.3
# define POS_Y 1
# define POS_X 2
# define DIR_Y 3
# define DIR_X 4
# define ROT 5

// MAP
# define PI 3.14159265
# define WALL 1
# define FLOOR 2
# define BLANK 3
# define PLAYER_NO 4
# define PLAYER_SO 5
# define PLAYER_EA 6
# define PLAYER_WE 7
# define INVALID_CHAR 8
# define Y 9
# define X 10
# define CAM_Y 11
# define CAM_X 12

/***********************************************/
/*					Structs						*/
/***********************************************/

typedef struct s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct s_player
{
	double	rotation;
	t_pos	plane;
	t_pos	dir;
	t_pos	pos;
}				t_player;

typedef struct s_ray
{
	t_pos	pos;
	t_pos	dir;
	t_pos	camera;
	double	cam_x;
	double	plane_size;
}				t_ray;

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

typedef struct s_texture
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	unsigned int	floor;
	unsigned int	ceiling;
}				t_texture;

typedef struct s_map
{
	char		**layout;		// info lido do file
	int			max_x;
	int			max_y;
	double		offset_x;
	double		offset_y;
	int			**int_map;
	char		**map;
	t_texture	*texture;	// info das texturas
}				t_map;

typedef struct s_cub
{
	char		*filename;
	t_player	player;
	t_ray		ray;
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
void			my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void			init_game(t_cub	*cub, const char *filename);
void			init_mlx(t_cub *cub, const char *filename);
void			setup_hook(void);
int				player(int flag);
// Trash
void			print_map(void);

/*************************************************/
/******************* PARSER **********************/
/*************************************************/

// Parser
int				file_check(void);
void			read_map(void);
char			**read_lines(int lines);
int				count_lines(void);

// Check Map
int				check_textures(t_map *map, char **content, int *i);
int				check_top_bottom(char *line);
int				check_middle(char **content, int *j);
int				check_map_conditions(char **content, int *i);
int				check_valid_chars(char **content);

// Parser Conditions
void			init_map(t_map *map);
int				check_map(char	**content, int *i);
void			get_map2(t_map	*map, char **content, int i);
void			get_map(t_map	*map, char **content, int i);
void			parse_map(t_map *map, char	**content);

// Parser Utils
int				is_texture(char *str);
int				is_floor(char *str);
int				is_player(char c);
int				have_textures(t_texture *t);
int				is_map(char c);
int				is_map_line(char	*line);

// Map info
int				get_textures(t_map *map, char *line, int *i);
int				get_floor(t_map *map, char *line, int *i);

// Map info utils
unsigned int	get_rgb(int r, int g, int b);
void			init_player(char p, int x, int y);

/*************************************************/
/******************* RENDER **********************/
/*************************************************/

// Render
int				start_game(void);

// LOAD
void			load(void);
double			get_radian(int angle);
void			draw_line(double x, double y, t_pos dir);

// Minimap
void			start_minimap(void);

//Raycast
void    		raycast(void);

/*************************************************/
/******************* MOVEMENT ********************/
/*************************************************/

// Movement
int				check_key(int keysym);

// Movement2
void			move_right(void);
void			move_left(void);
void			move_backward(void);
void			move_forward(void);

// Rotation
void			rotate_key(int key);


#endif