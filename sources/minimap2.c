/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:40:11 by rda-cunh          #+#    #+#             */
/*   Updated: 2025/03/31 19:32:13 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	draw_square2(int i, int j)
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
				my_mlx_pixel_put(game(), offsize_x + x, offsize_y + y, BLACK_PIXEL);
			else if (game()->map->int_map[i][j] == FLOOR)
				my_mlx_pixel_put(game(), offsize_x + x, offsize_y + y, GRAY_PIXEL);
			x++;
		}
		y++;
	}
}

void	start_map2(void)
{
	int	i;
	int	j;

	i = 0;
	while (game()->map->int_map[i])
	{
		j = 0;
		while (game()->map->int_map[i][j])
		{
			draw_square2(i, j);
			j++;
		}
		i++;
	}
}
