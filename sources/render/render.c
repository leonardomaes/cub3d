/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/20 19:29:43 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int start_game(void)
{
	int i;
	int j;

	ft_bzero(game()->mlx->addr, WINDOW_WIGTH * WINDOW_HEIGHT * (game()->mlx->bits_per_pixel / 8));
	i = 0;
	while (i <= WINDOW_HEIGHT)
	{
		j = 0;
		while (j <= WINDOW_WIGTH)
		{
			if (i > (WINDOW_HEIGHT / 2))
				my_mlx_pixel_put(game(), j, i, game()->map->texture->ceiling);
			else
				my_mlx_pixel_put(game(), j, i, game()->map->texture->floor);
			j++;
		}
		i++;
	}
	draw_minimap(game());
	mlx_put_image_to_window(game()->mlx->mlx, game()->mlx->win, game()->mlx->img, 0, 0);
	return (0);
}
