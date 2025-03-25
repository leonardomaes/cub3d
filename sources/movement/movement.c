/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/25 00:37:17 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
void	do_key(int key)
{
	if (key == XK_a)
	{
		if (game()->player.rotation == 1)
			game()->player.rotation = 360;
		else
			game()->player.rotation -= 1;
		printf("%f\n", game()->player.rotation);
	}
	if (key == XK_d)
	{
		if (game()->player.rotation == 360)
			game()->player.rotation = 1;
		else
			game()->player.rotation += 1;
		printf("%f\n", game()->player.rotation);
	}
}
*/

int	is_movement_key(int key)
{
	return (key == XK_w || key == XK_s || key == XK_a || key == XK_d);
}

int	valid_move(double new_x, double new_y)
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
	t_player	*player;

	player = &game()->player;
	new_x = player->pos.x + player->dir.x * MOVE_SPEED;
	new_y = player->pos.y + player->dir.y * MOVE_SPEED;
	if (valid_move(new_x, new_y))
	{
		player->pos.x = new_x;
		player->pos.y = new_y;
	}
}

void	move_backward(void)
{
	double		new_x;
	double		new_y;
	t_player	*player;

	player = &game()->player;
	new_x = player->pos.x - player->dir.x * MOVE_SPEED;
	new_y = player->pos.y - player->dir.y * MOVE_SPEED;
	if (valid_move(new_x, new_y))
	{
		player->pos.x = new_x;
		player->pos.y = new_y;
	}
}

void	move_left(void)
{
	double		new_x;
	double		new_y;
	t_player	*player;

	player = &game()->player;
	new_x = player->pos.x + player->dir.x * MOVE_SPEED;
	new_y = player->pos.y - player->dir.y * MOVE_SPEED;
	if (valid_move(new_x, new_y))
	{
		player->pos.x = new_x;
		player->pos.y = new_y;
	}
}

void	move_right(void)
{
	double		new_x;
	double		new_y;
	t_player	*player;

	player = &game()->player;
	new_x = player->pos.x - player->dir.x * MOVE_SPEED;
	new_y = player->pos.y + player->dir.y * MOVE_SPEED;
	if (valid_move(new_x, new_y))
	{
		player->pos.x = new_x;
		player->pos.y = new_y;
	}
}

void	handle_movement(int key)
{
	if (key == XK_w)
		move_forward();
	else if (key == XK_s)
		move_backward();
	else if (key == XK_a)
		move_left();
	else if (key == XK_d)
		move_right();
}

int	check_key(int keysym)
{
	if (keysym == XK_Escape)
		kill_all();
	if (is_movement_key(keysym))
		handle_movement(keysym);
	return (0);
}
