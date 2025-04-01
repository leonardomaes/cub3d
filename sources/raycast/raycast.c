/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/01 20:07:40 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    init_ray(t_ray *ray) // change this for the init functions
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
    ray->side = 0;
}

static void init_raycast(int x, t_ray *ray, t_player *player)
{
    init_ray(ray); //init ray struct values
    ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
    ray->dir_x = player->dir.x + player->plane.x * ray->camera_x;
    ray->dir_y = player->dir.y + player->plane.y * ray->camera_x;
    ray->map_x = (int)player->pos.x;
    ray->map_y = (int)player->pos.y;
    ray->deltadist_x = fabs(1 / ray->dir_x);
    ray->deltadist_y = fabs(1 / ray->dir_y);
}

static void set_dda(t_ray *ray, t_player *player)
{
    if (ray->dir_x < 0)
    {
        ray->step_x = -1;
        ray->sidedist_x = (player->pos.x - ray->map_x) * ray->deltadist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->sidedist_x = (ray->map_x + 1.0 - player->pos.x) * ray->deltadist_x;
    }
    if (ray->dir_y < 0)
    {
        ray->step_y = -1;
        ray->sidedist_y = (player->pos.y - ray->map_y) * ray->deltadist_y;
    }
    else
    {
        ray->step_y = -1;
        ray->sidedist_y = (ray->map_y + 1.0 - player->pos.y) * ray-> deltadist_y;
    }
}

void static perform_dda(t_ray *ray)
{
    int hit;

    hit = 0;
    while (hit == 0)
    {
        if(ray->sidedist_x < ray->sidedist_y)
        {
            ray->sidedist_x += ray->sidedist_x;
            ray->map_x += ray->step_x;
            ray->side = 0; 
        }
        else
        {
            ray->sidedist_y += ray->sidedist_y;
            ray->map_y += ray->step_y;
            ray->side = 1; 
        }
        if (ray->map_y < 0.25
                || ray->map_x < 0.25
                || ray->map_y > game()->map->max_y - 0.25
                || ray->map_x > game()->map->max_x - 0.25)
                break ;
        else if (game()->map->map[ray->map_x][ray->map_y] > '0')
            hit = 1;
    }
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
        set_dda(&ray, player);
        perform_dda(&ray);
        x++;
    }
    return (1);
}