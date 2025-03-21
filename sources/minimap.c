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

#include "../includes/cub3d.h"


void	draw_square(int i, int j)
{
	int		x;
	int		y;
	double	offsize_x;
	double	offsize_y;

	offsize_x = j * ((WINDOW_WIDTH / game()->map->max_x) * MAP_SCALE);
	offsize_y = i * ((WINDOW_HEIGHT / game()->map->max_y) * MAP_SCALE);
	y = 1;
	while (y < (MAP_SCALE * 100))
	{
		x = 1;
		while (x < (MAP_SCALE * 100))
		{
			if (game()->map->int_map[i][j] == WALL || game()->map->int_map[i][j] == BLANK)
				my_mlx_pixel_put(game(), offsize_x + x, offsize_y + y, BLACK_PIEXL);
			else if (game()->map->int_map[i][j] == FLOOR)
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
	while (game()->map->int_map[i])
	{
		j = 0;
		while (game()->map->int_map[i][j])
		{
			draw_square(i, j);
			j++;
		}
		i++;
	}
}
