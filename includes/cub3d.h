/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:49:40 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/15 00:24:01 by rda-cunh         ###   ########.fr       */
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
# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 600
# define FOV 66.00

// Colors
# define RED_PIXEL 0xFF0000
# define BLUE_PIXEL 0x0000FF
# define GREEN_PIXEL 0x00FF00
# define YELLOW_PIXEL 0xFFFF00
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define GRAY_PIXEL 0xAAAAAA

// MAP SETTINGS
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 5.0
# define MOUSE_SENSIBILITY 0.1
# define PLAYER_OFFSET 0.15
# define MAP_OFFSET 20
# define MINIMAP_MAX_SIZE 25
# define FOV_ANGLE 0.66
# define POS_Y 1
# define POS_X 2
# define DIR_Y 3
# define DIR_X 4
# define ROT 5
# define NORTH 6
# define SOUTH 7
# define EAST 8
# define WEST 9

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

typedef struct s_ray
{
	double	camera_x; //helps mapping the vertical screen collumns to camera plane coordinates (it ranges from -1 to 1)
	double	dir_x; 
	double	dir_y; // sets the direction vectors of each ray (used for DDA calculations)
	int		map_x;
	int 	map_y; // current map celll (int pair of number), used to check collisions
	int		step_x;
	int		step_y; // determines the movement directtion in the game grid (1 for right/down, -1 for left/up)
	double	sidedist_x;
	double	sidedist_y; // used in dda: distance from player position to the x/y gridline
	double	deltadist_x;
	double	deltadist_y; // used in dda: distance between grid lines in ray direction
	double	wall_dist; // perpenticular distance to hit wall (used to correct perspective)
	double	wall_x; // exact position on wall (for texture porpuses)
	int		side; // wall side flag (0 for x side (vertical) and 1 for y side (horizontal)): used for shading and texture orientation
	int		line_height;
	int		draw_start;
	int		draw_end; // walls rendering parameters
	int		wall_color; // for testing porpuses with colors
}				t_ray;

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
	unsigned int	floor;
	unsigned int	ceiling;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				size;
	int				width;
	int				height;
	int				**no_color;
	int				**so_color;
	int				**we_color;
	int				**ea_color;
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
	double		minimap_scale;
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

// INIT
void			init_mlx(t_cub *cub, const char *filename);
void			init_ray(t_ray *ray);
void			init_player(char p, int x, int y);



// UTILS
void			my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
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

/*************************************************/
/******************* RENDER **********************/
/*************************************************/

// Render
int				start_game(void);

// LOAD
void			load_texture(void);
double			get_radian(int angle);
void			draw_line(double x, double y, t_pos dir);

// Minimap
void			draw_square(int i, int j);
void			start_minimap(void);

//Raycast
int				raycast(t_player *player);

/*************************************************/
/******************* MOVEMENT ********************/
/*************************************************/

// Movement
int				is_key(int key);
void			move_key(int key);
void			do_key(int key);
int				check_key(int keysym);

// Movement2
void			move_right(void);
void			move_left(void);
void			move_backward(void);
void			move_forward(void);

// Rotation
void			rotate_key(int key);
int				handle_mouse_move(int x, int y, void *param);

#endif