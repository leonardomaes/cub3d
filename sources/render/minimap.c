/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:40:11 by rda-cunh          #+#    #+#             */
/*   Updated: 2025/04/14 18:59:41 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* static void	draw_player(void)
{
	int		x;
	int		y;
	double	offsize_x;
	double	offsize_y;

	offsize_x = game()->player.pos.x * (game()->map->offset_x * MAP_SCALE) + MAP_OFFSET;
	offsize_y = game()->player.pos.y * (game()->map->offset_y * MAP_SCALE) + MAP_OFFSET;
	y = -3;
	while (y < 3)
	{
		x = -3;
		while (x < 3)
		{
			my_mlx_pixel_put(game(), offsize_x + x, offsize_y + y, RED_PIXEL);
			x++;
		}
		y++;
	}
	draw_line(player(POS_X) + MAP_OFFSET, player(POS_Y) + MAP_OFFSET, game()->player.dir);
}

void	draw_square(int i, int j)
{
	int		x;
	int		y;
	double	offsize_x;
	double	offsize_y;

	offsize_x = j * (game()->map->offset_x * MAP_SCALE) + MAP_OFFSET;
	offsize_y = i * (game()->map->offset_y * MAP_SCALE) + MAP_OFFSET;
	y = 1;
	while (y < (MAP_SCALE * 100))
	{
		x = 1;
		while (x < (MAP_SCALE * 100))
		{
			if (game()->map->map[i][j] == '1' || game()->map->int_map[i][j] == ' ')
				my_mlx_pixel_put(game(), offsize_x + x, offsize_y + y, BLACK_PIXEL);
			else if (game()->map->map[i][j] == '0' || is_player(game()->map->map[i][j]))
				my_mlx_pixel_put(game(), offsize_x + x, offsize_y + y, GRAY_PIXEL);
			x++;
		}
		y++;
	}
}

void	start_minimap(void)
{
	int	i;
	int	j;

	i = 0;
	while (game()->map->map[i])
	{
		j = 0;
		while (game()->map->map[i][j])
		{
			draw_square(i, j);
			j++;
		}
		i++;
	}
	draw_player();
} */

static void	draw_fov(void)
{
	t_pos	line_left;
	t_pos	line_right;
	int		cell_size;
	double	player_x;
	double	player_y;

	// Calculate cell size (like in draw_square)
    cell_size = floor(game()->map->minimap_scale * 100);

	// Calculate/adjust player position using cell_size
	player_x = game()->player.pos.x * cell_size + MAP_OFFSET;
	player_y = game()->player.pos.y * cell_size + MAP_OFFSET;

	// Calculate FOV lines
	line_left.x = game()->player.dir.x - game()->player.plane.x;
	line_left.y = game()->player.dir.y - game()->player.plane.y;
	line_right.x = game()->player.dir.x + game()->player.plane.x;
	line_right.y = game()->player.dir.y + game()->player.plane.y;

	// Draw FOV lines using the recalculated player position
	draw_line(player_x, player_y, line_left);
	draw_line(player_x, player_y, game()->player.dir);
	draw_line(player_x, player_y, line_right);
}

static void	draw_player(void)
{
	int		x;
	int		y;
	double	offsize_x;
	double	offsize_y;
	int		cell_size;

	cell_size = floor(game()->map->minimap_scale * 100);
	offsize_x = game()->player.pos.x * cell_size + MAP_OFFSET;
	offsize_y = game()->player.pos.y * cell_size + MAP_OFFSET;
	y = -3;
	while (y < 3)
	{
		x = -3;
		while (x < 3)
		{
			my_mlx_pixel_put(game(), offsize_x + x, offsize_y + y, RED_PIXEL);
			x++;
		}
		y++;
	}
}

void	draw_square(int i, int j)
{
	int		x;
	int		y;
	double	offsize_x;
	double	offsize_y;
	int		cell_size;

	cell_size = floor(game()->map->minimap_scale * 100);
	offsize_x = j * cell_size + MAP_OFFSET;
	offsize_y = i * cell_size + MAP_OFFSET;
	y = 0;
	while (y < cell_size)
	{
		x = 0;
		while (x < cell_size)
		{
			if (game()->map->map[i][j] == '1'
				|| game()->map->int_map[i][j] == ' ')
				my_mlx_pixel_put(game(), offsize_x + x, offsize_y + y, BLACK_PIXEL);
			else if (game()->map->map[i][j] == '0'
				|| is_player(game()->map->map[i][j]))
				my_mlx_pixel_put(game(), offsize_x + x, offsize_y + y, GRAY_PIXEL);
			x++;
		}
		y++;
	}
}

static double	get_scale(void)
{
	int	max_dim;

	max_dim = 0;
	max_dim = fmax((double)game()->map->max_x, (double)game()->map->max_y);

	if (max_dim <= 5)
		return (0.3);  // very small maps
	else if (max_dim <= 10)
		return (0.2);  // medium maps
	else
		return (0.12);  // large maps
}

void	start_minimap(void)
{
	int	i;
	int	j;

	if (game()->map->max_x > MINIMAP_MAX_SIZE 
		|| game()->map->max_y > MINIMAP_MAX_SIZE)
		return ;

	game()->map->minimap_scale = get_scale();
	i = 0;
	while (game()->map->map[i])
	{
		j = 0;
		while (game()->map->map[i][j])
		{
			draw_square(i, j);
			j++;
		}
		i++;
	}
	draw_player();
	draw_fov();
}
