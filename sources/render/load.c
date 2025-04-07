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

int	get_pixel_color(int size_line, int bpp, char *addr, int x, int y)
{
	int	offset;

	offset = (y * size_line) + (x * (bpp / 8));
	return (*(int *)(addr + offset));
}

int	**get_texture(char	*path)	// Falta fazer os FREEs
{
	t_mlx	tex;
	int		**buffer;
	int		x;
	int		y;

	tex.img = mlx_xpm_file_to_image(game()->mlx->mlx, path, &tex.width, &tex.height);
	if (!tex.img)
		ft_exit("Fail to load image\n", 1);
	tex.addr = mlx_get_data_addr(tex.img, &tex.bits_per_pixel, &tex.line_length, &tex.endian);
	buffer = malloc(sizeof(int *) * tex.height);
	if (!buffer)
		ft_exit("Allocation failed\n", 1);
	y = 0;
	while (y < tex.height)
	{
		buffer[y] = malloc(sizeof(int) * tex.width);
		if (!buffer[y])
			return (NULL);
		x = 0;
		while (x < tex.width)
		{
			buffer[y][x] = get_pixel_color(tex.line_length, tex.bits_per_pixel, tex.addr, x, y);
			printf("teste:%d\n", buffer[y][x]);
			x++;
		}
		y++;
	}
	return (buffer);
}

void	load_texture()
{
	game()->map->texture->no_color = get_texture(game()->map->texture->no_path);
	game()->map->texture->so_color = get_texture(game()->map->texture->so_path);
	game()->map->texture->we_color = get_texture(game()->map->texture->we_path);
	game()->map->texture->ea_color = get_texture(game()->map->texture->ea_path);
}
