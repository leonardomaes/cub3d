/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/12 12:52:10 by lmaes            ###   ########.fr       */
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
		game()->player.dir.x = 0;
		game()->player.dir.y = 1;
	}
	else if (p == 'S')
	{
		game()->player.dir.x = 0;
		game()->player.dir.y = -1;
	}
	else if (p == 'W')
	{
		game()->player.dir.x = -1;
		game()->player.dir.y = 0;
	}
	else if (p == 'E')
	{
		game()->player.dir.x = 1;
		game()->player.dir.y = 0;
	}
	
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