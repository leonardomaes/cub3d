/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/16 18:46:01 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clear_map(void)
{
	int	i;

	if (game()->map)
	{
		if (game()->map->layout)
		{
			i = 0;
			while (game()->map->layout[i])
				free(game()->map->layout[i++]);
			free(game()->map->layout);
		}
		if (game()->map->map)
		{
			i = 0;
			while (game()->map->map[i])
				free(game()->map->map[i++]);
			free(game()->map->map);
		}
		if (game()->map->int_map)
		{
			i = 0;
			while (game()->map->int_map[i])
				free(game()->map->int_map[i++]);
			free(game()->map->int_map);
		}
		if (game()->map->texture->no_color)
			free_texture_split(game()->map->texture->no_color);
		if (game()->map->texture->so_color)
			free_texture_split(game()->map->texture->so_color);
		if (game()->map->texture->we_color)
			free_texture_split(game()->map->texture->we_color);
		if (game()->map->texture->ea_color)
			free_texture_split(game()->map->texture->ea_color);
		if (game()->map->texture)
		{
			free(game()->map->texture->ea_path);
			free(game()->map->texture->no_path);
			free(game()->map->texture->so_path);
			free(game()->map->texture->we_path);
			free(game()->map->texture);
		}
		free(game()->map);
	}
}

void	clear_all(void)
{
	if (!game())
		return ;
	clear_mlx(game()->mlx);
	clear_map();
}

int	kill_all(void)
{
	clear_all();
	write(1, "Closed\n", 8);
	exit(1);
	return (0);
}

void	ft_exit(char *msg, int exit_code)
{
	ft_printf(msg);
	clear_all();
	exit(exit_code);
}
