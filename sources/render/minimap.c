/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:40:11 by rda-cunh          #+#    #+#             */
/*   Updated: 2025/04/13 22:41:28 by rda-cunh         ###   ########.fr       */
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

static void draw_fov(void)
{
	t_pos	line_left;
	t_pos	line_right;

	//calculate left and right FOV line using vector operations
	line_left.x = game()->player.dir.x - game()->player.plane.x;
	line_left.y = game()->player.dir.y - game()->player.plane.y;
	line_right.x = game()->player.dir.x + game()->player.plane.x;
	line_right.y = game()->player.dir.y + game()->player.plane.y;

	//draw left FOV line
	draw_line(player(POS_X) + MAP_OFFSET, player(POS_Y) + MAP_OFFSET, line_left);

	//draw centre direction line
	draw_line(player(POS_X) + MAP_OFFSET, player(POS_Y) + MAP_OFFSET, game()->player.dir);

	//draw right FOV line
	draw_line(player(POS_X) + MAP_OFFSET, player(POS_Y) + MAP_OFFSET, line_right);
}

static void	draw_player(void)
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
//	draw_line(player(POS_X), player(POS_Y), game()->player.dir);
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
	draw_fov();
}
