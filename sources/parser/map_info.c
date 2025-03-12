/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/06 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	set_textures(t_map *map, char *dir, char *path)
{
	if (!dir || !path)
		return (1);
	if (!ft_strcmp(dir, "NO") && !map->texture->no_path)
		map->texture->no_path = ft_chartrim(path, '\n');
	else if (!ft_strcmp(dir, "SO") && !map->texture->so_path)
		map->texture->so_path = ft_chartrim(path, '\n');
	else if (!ft_strcmp(dir, "WE") && !map->texture->we_path)
		map->texture->we_path = ft_chartrim(path, '\n');
	else if (!ft_strcmp(dir, "EA") && !map->texture->ea_path)
		map->texture->ea_path = ft_chartrim(path, '\n');
	else if (dir[0] != '\n')
		return (1);
	return (0);
}

int	get_textures(t_map *map, char *line, int *i)
{
	char	**wall;

	if (line[0] == '\n')
		return ((*i)++, 0);
	wall = ft_split(line, ' ');
	if (!wall)
		return (1);
	if (set_textures(map, wall[0], wall[1]) == 1)
		return (free_split(wall), 1);
	free_split(wall);
	(*i)++;
	return (0);
}

int	set_floor(t_map *map, char *fc, char *rgb)
{
	int		i;
	int		j;
	unsigned int		nbr;
	char	**temp;

	if (!fc || !rgb)
		return (1);
	temp = ft_split(rgb, ',');
	i = 0;
	while (temp[i]) // Verificar se são todos numeros
	{
		j = 0;
		while (temp[i][j])
		{
			if (ft_isdigit(temp[i][j]) == 0)
				return (free_split(temp), 1);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (free_split(temp), 1);
	nbr = rgb_to_hex(ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
	if (!ft_strcmp(fc, "F\0") && map->texture->floor == 0)
		map->texture->floor = nbr;
	else if (!ft_strcmp(fc, "C\0") && map->texture->ceiling == 0)
		map->texture->ceiling = nbr;
	else
		return (free_split(temp), 1);
	free_split(temp);
	return (0);
}

int	get_floor(t_map *map, char *line, int *i)
{
	char	**floor;
	char	*rgb;

	if (line[0] == '\n')
		return ((*i)++, 0);
	floor = ft_split(line, ' ');
	if (!floor)
		return (1);
	rgb = ft_chartrim(floor[1], '\n');
	if (set_floor(map, floor[0], rgb) == 1)
		return (free(rgb), free_split(floor), 1);
	if (get_hexa_color(map, floor[0]) == 1)
	return (free(rgb), free_split(floor), 1);
	free(rgb);
	free_split(floor);
	(*i)++;
	return (0);
}
