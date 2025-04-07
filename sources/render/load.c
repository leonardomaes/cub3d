/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/13 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_line(double x, double y, t_pos dir)
{
	int	i;

	i = 0;
	while (i++ < (MAP_SCALE * 100))
	{
		my_mlx_pixel_put(game(), x, y, RED_PIXEL);
		x += dir.x;
		y += dir.y;
	}
}

double	get_radian(int angle)
{
	double	radian;

	radian = angle * (PI / 180);
	return (radian);
}

int	**get_texture(char	*path)
{
	void	*img;
	int		size;

	img = mlx_xpm_file_to_image(game()->mlx->mlx, path, &size, &size);
	return (NULL);
}

void	load_texture()
{
	game()->map->texture->no_color = get_texture(game()->map->texture->no_path);
	game()->map->texture->so_color = get_texture(game()->map->texture->so_path);
	game()->map->texture->we_color = get_texture(game()->map->texture->we_path);
	game()->map->texture->ea_color = get_texture(game()->map->texture->ea_path);
}
