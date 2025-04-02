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
	double	cam_x;

	cam_x = 2.0 * ((double)x / (double)WINDOW_WIDTH) - 1.0;
	ray->pos = game()->player.pos;
	ray->dir.y = game()->player.dir.y + (game()->player.plane.y * cam_x);
	ray->dir.x = game()->player.dir.x + (game()->player.plane.x * cam_x);
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->plane_size = FOV / 100;
}

void	set_dda(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - (int)ray->pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = ((int)ray->pos.x + 1 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - (int)ray->pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = ((int)ray->pos.y + 1 - ray->pos.y) * ray->delta_dist.y;
	}
}

void	dda(t_ray *ray)
{
	int	is_wall;

	is_wall = 0;
	while (!is_wall)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->pos.y += ray->step.y;
			ray->side = 1;
		}
		if (ray->pos.y < 0.25
				|| ray->pos.x < 0.25
				|| ray->pos.y > game()->map->max_y - 0.25
				|| ray->pos.x > game()->map->max_x - 0.25)
				break ;
		if (game()->map->map[(int)ray->pos.y][(int)ray->pos.x])
			is_wall = 1;
	}
	
}

void	set_perp_walls(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->perp_wall_dist = (ray->side_dist.y - ray->delta_dist.y);
	ray->line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	ray->start = (-ray->line_height / 2 + WINDOW_HEIGHT / 2);
	if (ray->start < 0)
		ray->start = 0;
	ray->end = (ray->line_height / 2 + WINDOW_HEIGHT / 2);
	if (ray->end >= WINDOW_HEIGHT)
		ray->end = WINDOW_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = ray->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		ray->wall_x = ray->pos.x + ray->perp_wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	raycast(void)
{
	t_ray ray;
	int	x;

	x = 0;
	while (x <= WINDOW_WIDTH)
	{
		init_raycast(x, &ray);
		set_dda(&ray);
		dda(&ray);
		set_perp_walls(&ray);
		render_walls(&ray, X);
		x++;
	}
}