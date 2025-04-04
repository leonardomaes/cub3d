/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2024/07/11 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	player(int flag)
{
	if (flag == POS_Y)
		return (game()->player.pos.y * (game()->map->offset_y * MAP_SCALE));
	else if (flag == POS_X)
		return (game()->player.pos.x * (game()->map->offset_x * MAP_SCALE));
	else if (flag == DIR_X)
		return (game()->player.dir.x);
	else if (flag == DIR_Y)
		return (game()->player.dir.y);
	else if (flag == ROT)
		return (game()->player.rotation);
	else if (flag == X)
		return (game()->player.pos.x);
	else if (flag == Y)
		return (game()->player.pos.y);
	else if (flag == CAM_X)
		return (game()->player.plane.x);
	else if (flag == CAM_Y)
		return (game()->player.plane.y);
	return (0);
}

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->mlx->addr + (y * cub->mlx->line_length + x
			* (cub->mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_mlx(t_cub *cub, const char *filename)
{
	char	*title;

	cub->mlx = malloc(sizeof(t_mlx));
	if (!cub->mlx)
		exit (1);
	cub->mlx->mlx = mlx_init();
	if (!cub->mlx->mlx)
	{
		free(cub->mlx);
		exit (1);
	}
	cub->filename = (char *)filename;
	title = ft_strjoin("cub3D - ", filename);
	cub->mlx->win = mlx_new_window(cub->mlx->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, title);
	free(title);
	cub->mlx->img = mlx_new_image(cub->mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	cub->mlx->addr = mlx_get_data_addr(cub->mlx->img, &cub->mlx->bits_per_pixel, &cub->mlx->line_length, &cub->mlx->endian);
}

void	init_game(t_cub	*cub, const char *filename)
{
	init_mlx(cub, filename);
}

void	setup_hook(void)
{
	mlx_hook(game()->mlx->win, KeyPress, KeyPressMask, check_key, NULL);
	mlx_hook(game()->mlx->win, DestroyNotify, 0, kill_all, NULL);
	mlx_loop_hook(game()->mlx->mlx, &start_game, NULL);
	mlx_loop(game()->mlx->mlx);
}
