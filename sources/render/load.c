/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/13 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_wall_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			game()->map->texture->index = WEST;
		else
			game()->map->texture->index = EAST;
	}
	else
	{
		if (ray->dir.y > 0)
			game()->map->texture->index = SOUTH;
		else
			game()->map->texture->index = NORTH;
	}
}

void	render_walls(t_ray *ray, int x)
{
	int	y;
	int	color;

	y = ray->start;
	while (y < ray->end)
	{
		if (ray->side == 0)
			color = 0xFFFFFF; // Branco para paredes verticais
		else
			color = 0xAAAAAA; // Cinza para paredes horizontais
		my_mlx_pixel_put(game(), x, y, color);
		y++;
	}
}

/* void	render_walls(t_ray *ray, int x)
{
	int		y;
	
	get_wall_index(ray);
	y = ray->start;
	while (y < WINDOW_HEIGHT)
	{
		my_mlx_pixel_put(game(), x, y, RED_PIXEL);
		y++;	
	}
} */

void	draw_line(double x, double y, t_pos dir)
{
	int	i;

	i = 0;
	while (i++ < (MAP_SCALE * 100))
	{
		my_mlx_pixel_put(game(), x, y, RED_PIXEL);
		x += dir.x;
		y += dir.y;
	}
}

double	get_radian(int angle)
{
	double	radian;

	radian = angle * (PI / 180);
	return (radian);
}


void	load(void)
{
	
}