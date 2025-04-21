/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/10 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

int	is_map(char c)
{
	if (c == '0' || c == '1' || c == 'N'
		|| c == 'E' || c == 'S' || c == 'W' || c == ' ')
		return (0);
	return (1);
}

int	is_map_line(char *line)
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
