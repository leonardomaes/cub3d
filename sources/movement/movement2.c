/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/20 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	valid_move(double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (game()->map->map[map_y][map_x] == '1')
		return (0);
	return (1);
}

void	move_forward(void)
{
	double		new_x;
	double		new_y;

	new_x = game()->player.pos.x + game()->player.dir.x * MOVE_SPEED;
	new_y = game()->player.pos.y + game()->player.dir.y * MOVE_SPEED;
	if (valid_move(new_x, new_y))
	{
		game()->player.pos.x = new_x;
		game()->player.pos.y = new_y;
	}
}

void	move_backward(void)
{
	double		new_x;
	double		new_y;

	new_x = game()->player.pos.x - game()->player.dir.x * MOVE_SPEED;
	new_y = game()->player.pos.y - game()->player.dir.y * MOVE_SPEED;
	if (valid_move(new_x, new_y))
	{
		game()->player.pos.x = new_x;
		game()->player.pos.y = new_y;
	}
}

void	move_left(void)
{
	double		new_x;
	double		new_y;

	new_x = game()->player.pos.x + game()->player.dir.y * MOVE_SPEED;
	new_y = game()->player.pos.y - game()->player.dir.x * MOVE_SPEED;
	if (valid_move(new_x, new_y))
	{
		game()->player.pos.x = new_x;
		game()->player.pos.y = new_y;
	}
}

void	move_right(void)
{
	double		new_x;
	double		new_y;

	new_x = game()->player.pos.x - game()->player.dir.y * MOVE_SPEED;
	new_y = game()->player.pos.y + game()->player.dir.x * MOVE_SPEED;
	if (valid_move(new_x, new_y))
	{
		game()->player.pos.x = new_x;
		game()->player.pos.y = new_y;
	}
}



