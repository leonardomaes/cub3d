/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2024/07/11 12:52:10 by lmaes            ###   ########.fr       */
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
				my_mlx_pixel_put(game(), j, i, ft_atoi_hex(game()->map->texture->ceiling_color));
			else
				my_mlx_pixel_put(game(), j, i, ft_atoi_hex(game()->map->texture->floor_color));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game()->mlx->mlx, game()->mlx->win, game()->mlx->img, 0, 0);
	return (0);
}
