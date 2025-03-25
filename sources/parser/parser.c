/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/05/03 18:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_lines(void)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(game()->filename, O_RDONLY);
	if (fd == -1)
		ft_exit("ERROR: Unable to open file!\n", 1);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

char	**read_lines(int lines)
{
	int		fd;
	int		i;
	char	**map;
	char	*line;

	map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!map)
		ft_exit("ERROR: Memory allocation failed!\n", 1);
	fd = open(game()->filename, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		ft_exit("ERROR: Unable to open file!\n", 1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		free(line);
		if (!map[i])
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			close(fd);
			ft_exit("ERROR: Memory allocation failed!\n", 1);
		}
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	read_map(void)
{
	int		lines;

	lines = count_lines();
	if (lines == 0)
		ft_exit("ERROR: Empty file!\n", 1);
	game()->map = (t_map *)malloc(sizeof(t_map));
	if (!game()->map)
		ft_exit("ERROR: Memory allocation failed!\n", 1);
	game()->map->layout = read_lines(lines);
	parse_map(game()->map, game()->map->layout);
}

int	file_check(void)
{
	int	size;

	size = ft_strlen(game()->filename);
	if (ft_strncmp(game()->filename + (size - 4), ".cub", 4) != 0)
		ft_exit("ERROR:File specified in wrong format!\n", 1);
	read_map();
	return (0);
}
