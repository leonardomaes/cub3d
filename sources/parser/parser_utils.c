/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/10 12:52:10 by lmaes            ###   ########.fr       */
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

int	is_map(char c)
{
	if (!c || c == '0' || c == '1')
		return (0);
	return (1);
}

int	is_map_line(char	*line)
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
