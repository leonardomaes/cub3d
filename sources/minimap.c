/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:40:11 by rda-cunh          #+#    #+#             */
/*   Updated: 2025/03/20 19:17:17 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void draw_square(t_cub *cub, int x, int y, int color)
{
    int i;
    int j;
    int size;

    size = 10;
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            my_mlx_pixel_put(cub, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

void draw_minimap(t_cub *cub)
{
    int x;
    int y;
    
    y = 0;
        while (cub->map->layout[y])
    {
        x = 0;
        while (cub->map->layout[y][x])
        {
            if (cub->map->layout[y][x] == '1')
                draw_square(cub, x * 10, y * 10, 0x000000); // Black for walls
            else if (cub->map->layout[y][x] == '0')
                draw_square(cub, x * 10, y * 10, 0xAAAAAA); // Gray for floor
            x++;
        }
        y++;
    }
    // Draw player position (to add later)
}
