/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/08 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mlx(t_cub *cub, const char *filename)
{
	char	*title;

	cub->mlx = malloc(sizeof(t_mlx));
	if (!cub->mlx)
		exit (1);
	cub->mlx->mlx = mlx_init();
	if (!cub->mlx->mlx)
	{
		free(cub->mlx);
		exit (1);
	}
	cub->filename = (char *)filename;
	title = ft_strjoin("cub3D - ", filename);
	cub->mlx->win = mlx_new_window(cub->mlx->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, title);
	free(title);
	cub->mlx->img = mlx_new_image(cub->mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	cub->mlx->addr = mlx_get_data_addr(cub->mlx->img, &cub->mlx->bits_per_pixel,
			&cub->mlx->line_length, &cub->mlx->endian);
}

void	init_ray(t_ray *ray) // change this for the init functions
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->wall_color = 0;
}

void	init_raycast(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->dir_x = player->dir.x + player->plane.x * ray->camera_x;
	ray->dir_y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map_x = (int)player->pos.x;
	ray->map_y = (int)player->pos.y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

t_pos	get_plane(char flag)
{
	t_pos	value;

	if (flag == 'N')
	{
		value.x = (FOV / 100);
		value.y = 0;
	}
	else if (flag == 'S')
	{
		value.x = -(FOV / 100);
		value.y = 0;
	}
	else if (flag == 'W')
	{
		value.x = 0;
		value.y = -(FOV / 100);
	}
	else if (flag == 'E')
	{
		value.x = 0;
		value.y = (FOV / 100);
	}
	else
		return ((t_pos){0, 0});
	return (value);
}

void	init_player(char p, int x, int y)
{
	game()->player.pos.x = x + 0.5;
	game()->player.pos.y = y + 1.5;
	if (p == 'N')
	{
		game()->player.plane = get_plane('N');
		game()->player.rotation = 90;
	}
	else if (p == 'S')
	{
		game()->player.plane = get_plane('S');
		game()->player.rotation = 270;
	}
	else if (p == 'W')
	{
		game()->player.plane = get_plane('W');
		game()->player.rotation = 180;
	}
	else if (p == 'E')
	{
		game()->player.plane = get_plane('E');
		game()->player.rotation = 360;
	}
	game()->player.dir.y = -sin(get_radian(game()->player.rotation));
	game()->player.dir.x = cos(get_radian(game()->player.rotation));
}
