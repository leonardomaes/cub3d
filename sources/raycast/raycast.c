/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/13 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_raycast(int x, t_ray *ray)
{
	ray->cam_x = 2 * (x / WINDOW_WIDTH) - 1;
	ray->pos = game()->player.pos;
	ray->dir = game()->player.dir;
	ray->plane_size = FOV / 100;
}



void	raycast(void)
{
	t_ray ray;
	int	x;

	x = 0;
	while (x <= WINDOW_WIDTH)
	{
		init_raycast(x, &ray);
		x++;
	}
}