/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/16 18:41:31 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_line(double x, double y, t_pos dir)
{
	int	i;

	i = 0;
	while (i++ < (game()->map->minimap_scale * 100))
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

	tex.img = mlx_xpm_file_to_image(game()->mlx->mlx, path,
			&game()->map->texture->width, &game()->map->texture->height);
	if (!tex.img)
		ft_exit("Fail to load image\n", 1);
	tex.addr = mlx_get_data_addr(tex.img, &tex.bits_per_pixel,
			&tex.line_length, &tex.endian);
	buffer = malloc(sizeof(int *) * game()->map->texture->height);
	if (!buffer)
		ft_exit("Allocation failed\n", 1);
	y = 0;
	while (y < game()->map->texture->height)
	{
		buffer[y] = malloc(sizeof(int) * game()->map->texture->width);
		if (!buffer[y])
		{
			while (--y >= 0)
				free(buffer[y]);
			free(buffer);
			ft_exit("Allocation failed\n", 1);
		}
		x = 0;
		while (x < game()->map->texture->width)
		{
			buffer[y][x] = get_pixel_color(tex.line_length,
					tex.bits_per_pixel, tex.addr, x, y);
			x++;
		}
		y++;
	}
	printf("y:%d\n%d\n", y, game()->map->texture->height);
	printf("x:%d\n%d\n", x, game()->map->texture->width);
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
