/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/05 15:16:51 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned int	get_rgb(int r, int g, int b)
{
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

void	init_player(char p, int x, int y)
{
	game()->player.pos.x = x + 0.5;
	game()->player.pos.y = y + 1.5;
	if (p == 'N')
	{
		game()->player.rotation = 90;
		game()->player.plane.x = FOV_ANGLE;
		game()->player.plane.y = 0;
	}
	else if (p == 'S')
	{
		game()->player.rotation = 270;
		game()->player.plane.x = -FOV_ANGLE;
		game()->player.plane.y = 0;
	}
	else if (p == 'W')
	{
		game()->player.rotation = 180;
		game()->player.plane.x = 0;
		game()->player.plane.y = -FOV_ANGLE;
	}
	else if (p == 'E')
	{
		game()->player.rotation = 360;
		game()->player.plane.x = 0;
		game()->player.plane.y = FOV_ANGLE;
	}
	game()->player.dir.y = -sin(get_radian(game()->player.rotation));
	game()->player.dir.x = cos(get_radian(game()->player.rotation));
}

/* 
int	get_hexa_color(t_map *map, char *fc)
{
	char	hexa[] = "0123456789ABCDEF";
	char	hexa_str[11];
	int		value;
	int		i;

	if (!fc)
		return (1);
	if (!ft_strcmp(fc, "F\0"))
		value = map->texture->floor;
	else if (!ft_strcmp(fc, "C\0"))
		value = map->texture->ceiling;
	hexa_str[0] = '0';
	hexa_str[1] = 'x';
	i = 5;
	while (i >= 0)
	{
		hexa_str[i + 2] = hexa[value & 0xF];
		value >>= 4;
		i--;
	}
	hexa_str[8] = '\0';
	if (!ft_strcmp(fc, "F\0"))
		map->texture->floor_color = ft_strdup(hexa_str);
	else if (!ft_strcmp(fc, "C\0"))
		map->texture->ceiling_color = ft_strdup(hexa_str);
	return (0);
}
 */