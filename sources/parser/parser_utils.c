/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/21 01:42:01 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_texture(char *str)
{
	if (!ft_strcmp(str, "NO") || !ft_strcmp(str, "EA")
		|| !ft_strcmp(str, "SO") || !ft_strcmp(str, "WE")
		|| str[0] == '\n')
		return (1);
	return (0);
}

int	is_floor(char *str)
{
	if (!ft_strcmp(str, "F\0") || !ft_strcmp(str, "C\0"))
		return (1);
	return (0);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	have_textures(t_texture *t)
{
	int	size;

	size = 0;
	if (!t || !t->ea_path || !t->no_path || !t->so_path
			|| !t->we_path || t->ceiling == 0 || t->floor == 0)
		return (1);
	size = ft_strlen(t->ea_path);
	if (ft_strncmp(t->ea_path + (size - 4), ".xpm", 4) != 0)
		return (1);
	size = ft_strlen(t->no_path);
	if (ft_strncmp(t->no_path + (size - 4), ".xpm", 4) != 0)
		return (1);
	size = ft_strlen(t->so_path);
	if (ft_strncmp(t->so_path + (size - 4), ".xpm", 4) != 0)
		return (1);
	size = ft_strlen(t->we_path);
	if (ft_strncmp(t->we_path + (size - 4), ".xpm", 4) != 0)
		return (1);
	return (0);
}

int	is_map(char	*line)
{
	int	j;

	j = 0;
	if (!line)
		return (1);
	while (line[j])
	{
		if ((line[j] != '1' && line[j] != '0' && !ft_isspace(line[j])
				&& !is_player(line[j])))
			return (1);
		j++;
	}
	return (0);
}

int	check_top_bottom(char *line)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (line[j] != '1' && !ft_isspace(line[j]))
			return (1);
		j++;
	}
	return (0);
}

int extract_map_data(t_map *map)
{
	int	i;
	int	j;
	int	map_lines;

	// count how many map lines the map have
	i = 0;
	map_lines = 0;
	while (map->layout[i])
	{
		if (is_map(map->layout[i]) == 0)
			map_lines++;
		i++;
	}

	// Allocate memory
	map->map = (char **)malloc(sizeof(char *) * (map_lines + 1));
	if (!map->map)
		ft_exit("ERROR: Memory allocation failed!\n", 1);

	// Copy the map lines
	i = 0;
	j = 0;
	while (map->layout[i])
	{
		if (is_map(map->layout[i]) == 0)
		{
			map->map[j] = ft_strdup(map->layout[i]);
			if (!map->map[j])
			{
				// Clean up if strdup fails
				while (j > 0)
					free(map->map[--j]);
				free(map->map);
				return (1);
			}
			j++;
		}
		i++;
	}
	map->map[j] = NULL;
	return (0);
}

