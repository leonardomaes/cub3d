/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_conditions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:35:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/12 19:35:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_textures(t_map *map)
{
	map->texture = (t_texture *)malloc(sizeof(t_texture));
	map->texture->ceiling = 0;
	map->texture->floor = 0;
	map->texture->ea_path = NULL;
	map->texture->no_path = NULL;
	map->texture->so_path = NULL;
	map->texture->we_path = NULL;
}

int	check_textures(t_map *map, char **content, int *i)
{
	char	**wall;
	char	*temp;

	init_textures(map);
	while (content[*i])
	{
		wall = ft_split(content[*i], ' ');
		if (is_texture(wall[0]) == 1)
		{
			if (get_textures(map, content[*i], i) == 1)
				return (free_split(wall), 1);
		}
		else if (is_floor(wall[0]) == 1)
		{
			if (get_floor(map, content[*i], i) == 1)
				return (free_split(wall), 1);
		}
		else
			return (free_split(wall), 1);
		temp = ft_chartrim(content[*i], '\n');
		if (is_map(temp) == 0 && content[*i][0] != '\n')
		{
			free_split(wall);
			free(temp);
			break ;
		}
		free(temp);
		free_split(wall);
	}
	if (have_textures(map->texture) == 1)
		return (1);
	return (0);
}

int	check_valid_chars(char **content)
{
	int	j;

	j = 1;
	while (content[j])
	{
		if (is_map(content[j]) == 1)
			return (1);
		j++;
	}
	return (0);
}

int	check_middle(char **content, int *j)
{
	int	player;
	int	i;

	player = 0;
	while (is_map(content[*j + 1]) == 0 && content[*j + 1][0] != '\n')
	{
		i = 0;
		while (content[*j][i])
		{
			if (i == 0 && (content[*j][i] != '1'
				&& !ft_isspace(content[*j][i])))
				return (1);
			if (content[*j][i + 1] == '\n'
				&& content[*j][i] != '1')
				return (1);
			if (is_player(content[*j][i]))
				player++;
			i++;
		}
		(*j)++;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	check_map_conditions(char **content, int *i)
{
	int	j;

	j = *i;
	if (check_top_bottom(content[j]) == 1)
		return (1);
	j++;
	if (check_middle(content, &j) == 1)
		return (1);
	if (check_top_bottom(content[j]) == 1)
		return (1);
	j++;
	if (content[j])
		return (1);
	return (0);
}

int	check_map(char	**content, int *i)
{
	if (check_valid_chars(content + (*i)) == 1)
		return (1);
	if (check_map_conditions(content, i) == 1)
		return (1);
	return (0);
}

void	parse_map(t_map *map, char	**content)
{
	int	i;

	i = 0;
	if (!content)
		ft_exit("No map information\n", 1);
	if (check_textures(map, content, &i) == 1)
		ft_exit("Missing textures or in wrong format\n", 1);
	if (check_map(content, &i) == 1)
		ft_exit("Map in wrong format\n", 1);
}
