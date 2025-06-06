/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/06 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
	char	*dir;
	char	*value;

	if (line[0] == '\n')
		return ((*i)++, 0);
	wall = ft_split(line, ' ');
	if (!wall)
		return (1);
	dir = ft_spacetrim(wall[0]);
	value = ft_spacetrim(wall[1]);
	if (set_textures(map, dir, value) == 1)
		return (free_split(wall), 1);
	free_split(wall);
	free(dir);
	free(value);
	(*i)++;
	return (0);
}

int	set_floor(t_map *map, char *fc, char *rgb)
{
	unsigned int	nbr;
	char			**temp;

	temp = ft_split(rgb, ',');
	if (check_floors(temp) == 1)
		return (1);
	nbr = get_rgb(ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
	if (!ft_strcmp(fc, "F\0") && map->texture->floor == 0)
		map->texture->floor = nbr;
	else if (!ft_strcmp(fc, "C\0") && map->texture->ceiling == 0)
		map->texture->ceiling = nbr;
	else
		return (free_split(temp), 1);
	free_split(temp);
	return (0);
}

char	**get_colors(char *line, int i, int j)
{
	char	**result;
	char	*clean;

	result = malloc(sizeof(char *) * 3);
	if (!result)
		return (NULL);
	while (ft_isspace(*line))
		line++;
	result[0] = ft_substr(line, 0, 1);
	line++;
	while (ft_isspace(*line))
		line++;
	clean = malloc(ft_strlen(line) + 1);
	if (!clean)
		return (free(result[0]), free(result), NULL);
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			clean[j++] = line[i];
		i++;
	}
	clean[j] = '\0';
	result[1] = clean;
	result[2] = NULL;
	return (result);
}

int	get_floor(t_map *map, char *line, int *i)
{
	char	**floor;
	char	*rgb;
	int		k;
	int		j;

	k = 0;
	j = 0;
	if (line[0] == '\n')
		return ((*i)++, 0);
	floor = get_colors(line, k, j);
	if (!floor)
		return (1);
	rgb = ft_chartrim(floor[1], '\n');
	if (!rgb || ! floor[0])
		return (free(rgb), free_split(floor), 1);
	if (set_floor(map, floor[0], rgb) == 1)
		return (free(rgb), free_split(floor), 1);
	free(rgb);
	free_split(floor);
	(*i)++;
	return (0);
}
