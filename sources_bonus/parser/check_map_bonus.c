/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:35:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/22 20:35:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	check_textures(t_map *map, char **content, int *i)
{
	char	*wall;
	char	*temp;

	while (content[*i])
	{
		wall = get_split_line(content[*i]);
		if (is_texture(wall) == 1)
		{
			if (get_textures(map, content[*i], i) == 1)
				return (free(wall), 1);
		}
		else if (is_floor(wall) == 1)
		{
			if (get_floor(map, content[*i], i) == 1)
				return (free(wall), 1);
		}
		else
			return (free(wall), 1);
		temp = ft_chartrim(content[*i], '\n');
		if (is_map_line(temp) == 0 && content[*i][0] != '\n')
			return (free(wall), free(temp), have_textures(map->texture));
		free(temp);
		free(wall);
	}
	return (have_textures(map->texture));
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

int	check_player(char **content)
{
	int	player;
	int	y;
	int	x;

	player = 0;
	y = 0;
	while (is_map_line(content[y + 1]) == 0 && content[y + 1][0] != '\n')
	{
		x = 0;
		while (content[y][x])
		{
			if (is_player(content[y][x]))
			{
				player++;
				init_player(content[y][x], x, y);
			}
			x++;
		}
		y++;
	}
	if (player != 1)
		return (1);
	game()->map->max_y = y + 2;
	return (0);
}

int	check_middle(char **content, int *j)
{
	int	x;
	int	y;

	y = 0;
	while (is_map_line(content[y + 1]) == 0 && content[y + 1][0] != '\n')
	{
		x = 0;
		while (content[y][x])
		{
			if ((x == 0 && (content[y][x] != '1' && !ft_isspace(content[y][x])))
			|| (content[y][x + 1] == '\n' && (content[y][x] != '1'
				&& !ft_isspace(content[y][x])))
			|| ((content[y][x] == '0' || is_player(content[y][x])) &&
			(is_map(content[y -1][x]) == 1
				|| is_map(content[y +1][x]) == 1
				|| (x > 0 && is_map(content[y][x - 1]) == 1)
				|| (content[y][x + 1] && is_map(content[y][x + 1]) == 1))))
				return (1);
			x++;
		}
		y++;
	}
	*j += y;
	return (0);
}

int	check_map_conditions(t_map *map, char **content, int i)
{
	int	j;

	j = i;
	if (check_top_bottom(content[j]) == 1)
		return (1);
	j++;
	if (check_player(content + j) == 1)
		return (1);
	if (content[j][0] == '\n')
		return (1);
	if (get_map2(map, content, j - 1) == 1)
		return (1);
	if (check_middle(map->map + 1, &j) == 1)
		return (1);
	if (check_top_bottom(content[j]) == 1)
		return (1);
	j++;
	if (content[j])
		return (1);
	return (0);
}
