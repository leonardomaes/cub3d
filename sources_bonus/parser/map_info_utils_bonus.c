/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/12 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

unsigned int	get_rgb(int r, int g, int b)
{
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
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

char	*get_split_line(const char *s)
{
	char	**buff;
	char	*result;

	result = NULL;
	buff = ft_split(s, ' ');
	if (!buff)
		return (NULL);
	result = ft_spacetrim(buff[0]);
	if (result[0] == '\0')
	{
		free(result);
		result = ft_strdup(buff[0]);
	}
	free_split(buff);
	return (result);
}

int	check_valid_chars(char **content)
{
	int	j;

	j = 1;
	while (content[j])
	{
		if (is_map_line(content[j]) == 1)
			return (1);
		j++;
	}
	return (0);
}

int	check_floors(char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i])
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
	return (0);
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