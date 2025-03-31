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

static void init_raycast(int x, t_ray *ray, t_player *player)
{
    
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