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
}

int	check_map(t_map *map, char	**content, int *i)
{
	if (check_valid_chars(content + (*i)) == 1)
		return (1);
	if (check_map_conditions(map, content, *i) == 1)
		return (1);
	return (0);
}

char	*ft_mapdup(const char *s)
{
	char			*dest;
	int	i;

	if (!s || *s == '\n')
		return (NULL);
	dest = (char *)malloc(game()->map->max_x + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < game()->map->max_x)
	{
		if (i < (int)ft_strlen(s))
		{
			dest[i] = s[i];
		}
		else
			dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_map2(t_map	*map, char **content, int i)
{
	int	j;

	map->map = (char **)malloc(sizeof(char *) * (game()->map->max_y + 1));
	if (!map->map)
		return (1);
	j = 0;
	while (content[i])
	{
		map->map[j] = ft_mapdup(content[i]);	// Talvez trocar este strdup para preencher até o max_x
		if (!map->map[j] || map->map[j] == NULL)
			return (1);
		//printf(">%s", map->map[j]);
		j++;
		i++;
	}
	map->map[j] = NULL;
	map->offset_x = WINDOW_WIDTH / map->max_x;
	map->offset_y = WINDOW_HEIGHT / map->max_y;
	return (0);
}

void	parse_map(t_map *map, char	**content)
{
	int	i;

	i = 0;
	if (!content)
		ft_exit("Error\nNo map information\n", 1);
	init_map(game()->map);
	if (check_textures(map, content, &i) == 1)
		ft_exit("Error\nMissing textures or in wrong format\n", 1);
	if (check_map(map, content, &i) == 1)
		ft_exit("Error\nMap in wrong format\n", 1);
	//get_map2(map, content, i);
}
