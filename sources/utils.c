/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/14 18:48:59 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	player(int flag)
{
	if (flag == POS_Y)
		return (game()->player.pos.y * (game()->map->offset_y * game()->map->minimap_scale));
	else if (flag == POS_X)
		return (game()->player.pos.x * (game()->map->offset_x * game()->map->minimap_scale));
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

/* void	setup_hook(void)
{
	mlx_hook(game()->mlx->win, KeyPress, KeyPressMask, check_key, NULL);
	mlx_hook(game()->mlx->win, DestroyNotify, 0, kill_all, NULL);
	mlx_loop_hook(game()->mlx->mlx, &start_game, NULL);
	mlx_loop(game()->mlx->mlx);
} */

void	setup_hook(void)
{
	mlx_hook(game()->mlx->win, KeyPress, KeyPressMask, check_key, NULL);
	mlx_hook(game()->mlx->win, DestroyNotify, 0, kill_all, NULL);
	mlx_mouse_move(game()->mlx->mlx, game()->mlx->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2); // this centers the mouse on the window in the biggining of the game (to check if is needed or not)
	mlx_hook(game()->mlx->win, MotionNotify, PointerMotionMask, handle_mouse_move, NULL); // hook for mause handling
	mlx_mouse_hide(game()->mlx->mlx, game()->mlx->win); // this simply hides the mouse pointer in the game (to check if is needed)
	mlx_loop_hook(game()->mlx->mlx, &start_game, NULL);
	mlx_loop(game()->mlx->mlx);
}

