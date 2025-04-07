/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/20 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* void	rotate_key(int key)
{
	double	temp;
	double	rotspeed;

	temp = player(CAM_X);
	printf("A: %f\n", game()->player.plane.x);
	printf("B: %f\n", game()->player.plane.y);
	if (key == XK_Right)
	{
		rotspeed = -ROTATION_SPEED;
		game()->player.rotation -= ROTATION_SPEED;
		if (player(ROT) < 1)
			game()->player.rotation += 360;
	}
	if (key == XK_Left)
	{
		rotspeed = ROTATION_SPEED;
		game()->player.rotation += ROTATION_SPEED;
		if (player(ROT) > 360)
			game()->player.rotation -= 360;
	}
	game()->player.plane.x = game()->player.plane.x * cos(get_radian(rotspeed)) - game()->player.plane.y * sin(get_radian(rotspeed));
	game()->player.plane.y = temp * sin(get_radian(rotspeed)) + game()->player.plane.y * cos(get_radian(rotspeed));
	game()->player.dir.y = -sin(get_radian(game()->player.rotation));
	game()->player.dir.x = cos(get_radian(game()->player.rotation));
} */

void	rotate_key(int key)
{
	double	angle;

	// Update the rotation angle when pressing keys
	if (key == XK_Right)
	{
		game()->player.rotation -= ROTATION_SPEED;
		if (player(ROT) < 1)
			game()->player.rotation += 360;
	}
	else if (key == XK_Left)
	{
		game()->player.rotation += ROTATION_SPEED;
		if (player(ROT) > 360)
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

