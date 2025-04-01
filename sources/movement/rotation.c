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
	//double	temp_dir_x;
	double	temp_plane_x;
	double	rotspeed;

	//temp_dir_x = game()->player.dir.x;
	temp_plane_x = game()->player.plane.x;
	if (key == XK_Right)
	{
		rotspeed = -ROTATION_SPEED;
		game()->player.rotation -= ROTATION_SPEED;
		if (player(ROT) < 1)
			game()->player.rotation += 360;
	}
	else if (key == XK_Left)
	{
		rotspeed = ROTATION_SPEED;
		game()->player.rotation += ROTATION_SPEED;
		if (player(ROT) > 360)
			game()->player.rotation -= 360;
	}
	// game()->player.dir.x = temp_dir_x * cos(get_radian(rotspeed)) - game()->player.dir.y * sin(get_radian(rotspeed));
	// game()->player.dir.y = temp_dir_x * sin(get_radian(rotspeed)) + game()->player.dir.y * cos(get_radian(rotspeed));
	game()->player.dir.y = -sin(get_radian(game()->player.rotation));
	game()->player.dir.x = cos(get_radian(game()->player.rotation));

	game()->player.plane.x = temp_plane_x * cos(get_radian(rotspeed)) - game()->player.plane.y * sin(get_radian(rotspeed));
	game()->player.plane.y = temp_plane_x * sin(get_radian(rotspeed)) + game()->player.plane.y * cos(get_radian(rotspeed));
}

