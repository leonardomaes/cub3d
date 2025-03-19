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
		if (is_map_line(temp) == 0 && content[*i][0] != '\n')
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
		if (is_map_line(content[j]) == 1)
			return (1);
		j++;
	}
	return (0);
}

int	check_middle(char **content, int *j)
{
	int	player;
	int	x;
	int y;
	int	max_width;

	player = 0;
	y = 0;
	max_width = 0;
	while (is_map_line(content[y + 1]) == 0 && content[y + 1][0] != '\n')
	{
		x = 0;
		while (content[y][x])
		{
			if (x == 0 && (content[y][x] != '1'
				&& !ft_isspace(content[y][x])))
				return (1);
			if (content[y][x + 1] == '\n'
				&& content[y][x] != '1')
				return (1);
			if (content[y][x] == '0' && (is_map(content[y-1][x]) == 1 || is_map(content[y+1][x]) == 1))
				return (1);
			if (is_player(content[y][x]))
			{
				player++;
				game()->player.pos.x = x + 1;
				game()->player.pos.y = y + 2;
			}
			x++;
		}
		if (x > max_width)
			max_width = x;
		y++;
	}
	if (player != 1)
		return (1);
	game()->map->max_x = max_width;
	game()->map->max_y = y + 2;
	*j += y;
	return (0);
}

int	check_map_conditions(char **content, int *i)
{
	int	j;

	j = *i;
	if (check_top_bottom(content[j]) == 1)
		return (1);
	j++;
	if (check_middle(content + j, &j) == 1)	// J = Y
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

void	get_map(t_map	*map, char **content, int i)
{
	int	j;

	map->map = (char **)malloc(sizeof(char *) * (game()->map->max_y + 1));
	j = 0;
	while (content[i])
	{
		map->map[j] = ft_strdup(content[i]);
		j++;
		i++;
	}
	map->map[j] = NULL;
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
	get_map(map, content, i);
}
