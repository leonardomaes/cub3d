/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:35:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/21 14:38:17 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

// checks if it' a wall
static int	is_wall(char c)
{
	return (c == '1');
}

int	check_top_bottom(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	// skip spaces
	while (line[i] && line[i] == ' ')
		i++;
	// alll chars must be '1'
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_middle(char **content, int *j)
{
	int	y;
	int	x;
	int	first;
	int	last;

	y = *j;
	while (content[y] && is_map_line(content[y]))
	{
		// find first and last char in the line
		first = 0;
		while (content[y][first] && content[y][first] == ' ')
			first++;
		last = ft_strlen(content[y]) - 1;
		while (last > first && content[y][last] == ' ')
			last--;

		// check that both are
		if (!is_wall(content[y][first]) || !is_wall(content[y][last]))
			return (1);

		// check each cell for enclosure if it's a '0' or a player
		x = first;
		while (x <= last && (content[y][x] != '\n'))
		{
			if (content[y][x] == '0' || is_player(content[y][x]))
			{
				// check above
				if (y == 0 || x >= (int)ft_strlen(content[y - 1]) ||
					!is_map(content[y - 1][x]))
					return (1);
				// check below
				if (!content[y + 1] || x >= (int)ft_strlen(content[y + 1]) ||
					!is_map(content[y + 1][x]))
					return (1);
				// check left
				if (x == 0 || !is_map(content[y][x - 1]))
					return (1);
				// check right
				if (!content[y][x + 1] || !is_map(content[y][x + 1]))
					return (1);
			}
			x++;
		}
		y++;
	}
	*j = y - 1;
	return (0);
}

int	check_map_conditions(char **content, int *i)
{
	int	j;

	j = *i;
	// check top wall
	if (check_top_bottom(content[j]))
		return (1);
	j++;
	// check middle rows
	if (check_middle(content, &j))
		return (1);
	// check bottom wall
	if (check_top_bottom(content[j]))
		return (1);
	return (0);
}
