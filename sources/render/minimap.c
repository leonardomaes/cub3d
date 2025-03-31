/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:40:11 by rda-cunh          #+#    #+#             */
/*   Updated: 2025/03/21 01:30:21 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_player(void)
{
	int		x;
	int		y;
	double	offsize_x;
	double	offsize_y;

	offsize_x = game()->player.pos.x * (game()->map->offset_x * MAP_SCALE);
	offsize_y = game()->player.pos.y * (game()->map->offset_y * MAP_SCALE);
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
	draw_line(player(POS_X), player(POS_Y), game()->player.dir);
}

void	draw_square(int i, int j)
{
	int		x;
	int		y;
	double	offsize_x;
	double	offsize_y;

	offsize_x = j * (game()->map->offset_x * MAP_SCALE);
	offsize_y = i * (game()->map->offset_y * MAP_SCALE);
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

void	start_map(void)
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
}
