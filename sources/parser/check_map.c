/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:35:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/22 20:35:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_textures(t_map *map, char **content, int *i)
{
	char	**wall;
	char	*temp;

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
			if (content[y][x] == '0' && (is_map(content[y-1][x]) == 1 || is_map(content[y+1][x]) == 1)) // Erro por enquanto
				return (1);
			if (is_player(content[y][x]))
			{
				player++;
				init_player(content[y][x], x, y);
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
