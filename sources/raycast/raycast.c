/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/31 20:00:07 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    init_ray(t_ray *ray) // change this for the init functions
{
    ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->ray_pos_x = 0;
	ray->ray_pos_y = 0;
    ray->deltadist_x = 0;
    ray->deltadist_y = 0;
}

static void init_raycast(int x, t_ray *ray, t_player *player)
{
    init_ray(ray); //init ray struc values
    ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
    ray->dir_x = player->dir.x + player->plane.x * ray->camera_x;
    ray->dir_y = player->dir.y + player->plane.y * ray->camera_x;
    ray->ray_pos_x = (int)player->pos.x;
    ray->ray_pos_y = (int)player->pos.y;
    ray->deltadist_x = fabs(1 / ray->dir_x);
    ray->deltadist_y = fabs(1 / ray->dir_y);
}

int raycast(t_player *player)
{
    t_ray   ray;
    int     x;

    x = 0;
    ray = game()->ray;
    while (x < WINDOW_WIDTH)
    {
        init_raycast(x, &ray, player);
        //main loop
    }
    return (1);
}