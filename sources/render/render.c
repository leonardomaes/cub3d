/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/13 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	start_floors(void)
{
	int	i;
	int	j;

	ft_bzero(game()->mlx->addr, WINDOW_WIDTH * WINDOW_HEIGHT * (game()->mlx->bits_per_pixel / 8));
	i = 0;
	while (i <= WINDOW_HEIGHT)
	{
		j = 0;
		while (j <= WINDOW_WIDTH)
		{
			if (i > (WINDOW_HEIGHT / 2))
				my_mlx_pixel_put(game(), j, i, game()->map->texture->ceiling);
			else
				my_mlx_pixel_put(game(), j, i, game()->map->texture->floor);
			j++;
		}
		i++;
	}
}

int start_game(void)
{
	load();
	start_floors();
	start_minimap();
	raycast();
	mlx_put_image_to_window(game()->mlx->mlx, game()->mlx->win, game()->mlx->img, 0, 0);
	return (0);
}
