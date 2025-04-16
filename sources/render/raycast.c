/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/16 18:30:56 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos.x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos.x)
			* ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos.y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos.y)
			* ray->deltadist_y;
	}
}

static void	perform_dda(t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > game()->map->max_y - 0.25
			|| ray->map_x > game()->map->max_x - 0.25)
			break ;
		else if (game()->map->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

static void	calculate_wall_height(t_ray *ray, t_player *player)
{
	(void)player;
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(WINDOW_HEIGHT / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = game()->player.pos.y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = game()->player.pos.x + ray->wall_dist * ray->dir_x;
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
}

static void	draw_walls(t_ray *ray, int x)
{
	int	y;
	int	**tex;
	int	tex_x;
	int	tex_y;
	int	d;

	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			tex = game()->map->texture->ea_color;
		else
			tex = game()->map->texture->we_color;
	}
	else
	{
		if (ray->step_y > 0)
			tex = game()->map->texture->no_color;
		else
			tex = game()->map->texture->so_color;
	}
	tex_x = ray->wall_x * game()->map->texture->width;
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1
			&& ray->dir_y < 0))
		tex_x = game()->map->texture->width - tex_x - 1;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		d = (y * 256) - (WINDOW_HEIGHT * 128) + (ray->line_height * 128);
		tex_y = (d * game()->map->texture->height) / ray->line_height / 256;
		my_mlx_pixel_put(game(), x, y, tex[tex_y][tex_x]);
		y++;
	}
}

int	raycast(t_player *player)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = game()->ray;
	while (x < WINDOW_WIDTH)
	{
		init_raycast(x, &ray, player);
		set_dda(&ray, player);
		perform_dda(&ray);
		calculate_wall_height(&ray, player);
		draw_walls(&ray, x);
		x++;
	}
	return (0);
}
