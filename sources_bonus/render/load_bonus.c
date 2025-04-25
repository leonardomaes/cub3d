/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/16 18:41:31 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

double	get_radian(int angle)
{
	double	radian;

	radian = angle * (PI / 180);
	return (radian);
}

int	get_pixel_color(t_mlx tex, int x, int y)
{
	int	offset;

	offset = (y * tex.line_length) + (x * (tex.bits_per_pixel / 8));
	return (*(int *)(tex.addr + offset));
}

t_mlx	init_tex(char *path)
{
	t_mlx	tex;

	tex.img = mlx_xpm_file_to_image(game()->mlx->mlx, path,
			&game()->map->texture->width, &game()->map->texture->height);
	if (!tex.img)
	{
		tex.img = NULL;
		return (tex);
	}
	tex.addr = mlx_get_data_addr(tex.img, &tex.bits_per_pixel,
			&tex.line_length, &tex.endian);
	return (tex);
}

int	**get_texture(char	*path)
{
	t_mlx	tex;
	int		**buffer;
	int		x;
	int		y;

	tex = init_tex(path);
	if (tex.img == NULL)
		ft_exit("Fail to load image\n", 1);
	buffer = malloc(sizeof(int *) * game()->map->texture->height);
	if (!buffer)
		ft_exit("Allocation failed\n", 1);
	y = 0;
	while (y < game()->map->texture->height)
	{
		buffer[y] = malloc(sizeof(int) * game()->map->texture->width);
		if (!buffer[y])
			free_map_and_exit((char **)buffer, y, -1, "Allocation failed\n");
		x = -1;
		while (++x < game()->map->texture->width)
			buffer[y][x] = get_pixel_color(tex, x, y);
		y++;
	}
	mlx_destroy_image(game()->mlx->mlx, tex.img);
	return (buffer);
}

void	load_texture(void)
{
	game()->map->texture->no_color = get_texture(game()->map->texture->no_path);
	game()->map->texture->so_color = get_texture(game()->map->texture->so_path);
	game()->map->texture->we_color = get_texture(game()->map->texture->we_path);
	game()->map->texture->ea_color = get_texture(game()->map->texture->ea_path);
}
