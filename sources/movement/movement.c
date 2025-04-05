/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/05 15:21:23 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_key(int key)
{
	return (key == XK_w || key == XK_s || key == XK_a || key == XK_d || key == XK_Left || key == XK_Right);
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
void rotate_key(int key)
{
	double angle;

    // Update the rotation angle when pressing keys
    if (key == XK_Right)
    {
        game()->player.rotation -= ROTATION_SPEED;
        while (game()->player.rotation < 0)
            game()->player.rotation += 360;
    }
    else if (key == XK_Left)
    {
        game()->player.rotation += ROTATION_SPEED;
        while (game()->player.rotation >= 360)
            game()->player.rotation -= 360;
    }
    
    // Calculate direction vector from angle
    angle = get_radian(game()->player.rotation);
    game()->player.dir.x = cos(angle);
    game()->player.dir.y = -sin(angle);

	// for debugging porpuses - DELETE LATER
	printf("%f\n", game()->player.rotation);
	printf("cos/x: %f\n", game()->player.dir.x);
	printf("sin/y: %f\n", game()->player.dir.y);
    
    // Calculate camera plane perpendicular to direction (this was the part missing from previous implementation) - Also introduced FOV_ANGLE macro to insure relation withe the init_player function 
    game()->player.plane.x = -game()->player.dir.y * FOV_ANGLE;
    game()->player.plane.y = game()->player.dir.x * FOV_ANGLE;
}

void	move_key(int key)
{
	if (key == XK_a)
		move_left();
	if (key == XK_d)
		move_right();
	if (key == XK_w)
		move_forward();
	if (key == XK_s)
		move_backward();
}

void	do_key(int key)
{
	rotate_key(key);
	move_key(key);
}

int check_key(int keysym)
{
	if (keysym == XK_Escape)
		kill_all();
	if (is_key(keysym))
		do_key(keysym);
	return (0);
}
