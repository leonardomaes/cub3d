/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:49:40 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/17 00:53:03 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# define RED_P 0xFF0000
# define BLUE_P 0x0000FF
# define GREEN_P 0x00FF00
# define YELLOW_P 0xFFFF00
# define WHITE_P 0xFFFFFF
# define BLACK_P 0x000000
# define GRAY_P 0xAAAAAA

// MAP SETTINGS
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 5.0
# define MOUSE_SENSIBILITY 0.1
# define PLAYER_OFFSET 0.15
# define MAP_OFFSET 20
# define MINIMAP_MAX_SIZE 35
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
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		wall_color;
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

// INIT
void			init_mlx(t_cub *cub, const char *filename);
void			init_ray(t_ray *ray);
void			init_player(char p, int x, int y);
void			init_raycast(int x, t_ray *ray, t_player *player);

// UTILS
void			my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void			setup_hook(void);
int				player(int flag);

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
int				check_map_conditions(t_map *map, char **content, int i);

// Parser Conditions
void			init_map(t_map *map);
int				check_map(t_map *map, char	**content, int *i);
int				get_map2(t_map	*map, char **content, int i);
void			parse_map(t_map *map, char	**content);

// Parser Utils
int				is_texture(char *str);
int				is_floor(char *str);
int				is_player(char c);
int				is_map(char c);
int				is_map_line(char	*line);

// Map info
int				set_textures(t_map *map, char *dir, char *path);
int				get_textures(t_map *map, char *line, int *i);
int				set_floor(t_map *map, char *fc, char *rgb);
char			**get_colors(char *line, int i, int j);
int				get_floor(t_map *map, char *line, int *i);

// Map info utils
unsigned int	get_rgb(int r, int g, int b);
int				have_textures(t_texture *t);
char			*get_split_line(const char *s);
int				check_valid_chars(char **content);
int				check_floors(char **temp);

/*************************************************/
/******************* RENDER **********************/
/*************************************************/

// Render
void			draw_line(double x, double y, t_pos dir);
void			start_floors(void);
int				start_game(void);

// LOAD
void			load_texture(void);
double			get_radian(int angle);

// Minimap
void			draw_square(int i, int j);
void			start_minimap(void);

//Raycast
void			set_dda(t_ray *ray, t_player *player);
void			perform_dda(t_ray *ray);
void			calculate_wall_height(t_ray *ray, t_player *player);
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

/*************************************************/
/******************** FREE ***********************/
/*************************************************/

void			free_map_and_exit(char **map, int i, int fd, char *msg);
void			free_split(char **data);
void			free_texture_split(int **data);
void			clear_mlx(t_mlx *mlx);
void			clear_map(void);
void			clear_all(void);
int				kill_all(void);
void			ft_exit(char *msg, int exit_code);

#endif