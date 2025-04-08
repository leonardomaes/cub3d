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

void	init_map(t_map *map)
{
	map->texture = (t_texture *)malloc(sizeof(t_texture));
	map->texture->ceiling = 0;
	map->texture->floor = 0;
	map->texture->ea_path = NULL;
	map->texture->no_path = NULL;
	map->texture->so_path = NULL;
	map->texture->we_path = NULL;
	map->texture->ea_color = NULL;
	map->texture->we_color = NULL;
	map->texture->so_color = NULL;
	map->texture->no_color = NULL;
	map->map = NULL;
	map->int_map = NULL;
}

int	check_map(char	**content, int *i)
{
	if (check_valid_chars(content + (*i)) == 1)
		return (1);
	if (check_map_conditions(content, i) == 1)
		return (1);
	return (0);
}

void	get_map2(t_map	*map, char **content, int i)
{
	int	j;

	map->map = (char **)malloc(sizeof(char *) * (game()->map->max_y + 1));
	if (!map->map)
		return ;
	j = 0;
	while (content[i])
	{
		map->map[j] = ft_strdup(content[i]);
		if (!map->map[j])
		{
			while (j > 0)
				free(map->map[--j]);
			free(map->map);
			return;
		}
		j++;
		i++;
	}
	map->map[j] = NULL;
	map->offset_x = WINDOW_WIDTH / map->max_x;
	map->offset_y = WINDOW_HEIGHT / map->max_y;
}

void	get_map(t_map	*map, char **content, int i)
{
	int	y;
	int x;
	int row_len;

	map->int_map = (int **)malloc(sizeof(int *) * (game()->map->max_y + 1));
	if (!map->int_map)
		return ;
	y = 0;
	while (content[i])
	{
		row_len = ft_strlen(content[i]);
		map->int_map[y] = (int *)malloc(sizeof(int) * (row_len + 1));
		if (!map->int_map[y])
		{
			while (y > 0)
				free(map->int_map[--y]);
			free(map->int_map);
			return;
		}
		x = 0;
		while (content[i][x])
		{
			if (content[i][x] == '0')
				map->int_map[y][x] = FLOOR;
			else if (content[i][x] == '1')
				map->int_map[y][x] = WALL;
			else if (ft_isspace(content[i][x]))
				map->int_map[y][x] = BLANK;
			else if (content[i][x] == 'N')
				map->int_map[y][x] = PLAYER_NO;
			else if (content[i][x] == 'S')
				map->int_map[y][x] = PLAYER_SO;
			else if (content[i][x] == 'W')
				map->int_map[y][x] = PLAYER_WE;
			else if (content[i][x] == 'E')
				map->int_map[y][x] = PLAYER_EA;
			else
				map->int_map[y][x] = INVALID_CHAR;
			x++;
		}
		map->int_map[y][x] = 0;
		y++;
		i++;
	}
	map->int_map[y] = NULL;
	map->offset_x = WINDOW_WIDTH / map->max_x;
	map->offset_y = WINDOW_HEIGHT / map->max_y;
}

void	parse_map(t_map *map, char	**content)
{
	int	i;

	i = 0;
	if (!content)
		ft_exit("No map information\n", 1);
	init_map(game()->map);
	if (check_textures(map, content, &i) == 1)
		ft_exit("Missing textures or in wrong format\n", 1);
	if (check_map(content, &i) == 1)
		ft_exit("Map in wrong format\n", 1);
	get_map(map, content, i);
	get_map2(map, content, i);
}
