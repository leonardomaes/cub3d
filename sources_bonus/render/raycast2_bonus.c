/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/17 00:50:51 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	**select_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (game()->map->texture->ea_color);
		else
			return (game()->map->texture->we_color);
	}
	else
	{
		if (ray->step_y > 0)
			return (game()->map->texture->so_color);
		else
			return (game()->map->texture->no_color);
	}
}

static void	draw_walls(t_ray *ray, int x)
{
	int	y;
	int	**tex;
	int	tex_x;
	int	tex_y;
	int	d;

	tex = select_texture(ray);
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
