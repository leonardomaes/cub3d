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

void	rotate_key(int key)
{
	double	angle;

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
	angle = get_radian(game()->player.rotation);
	game()->player.dir.x = cos(angle);
	game()->player.dir.y = -sin(angle);
	game()->player.plane.x = -game()->player.dir.y * FOV_ANGLE;
	game()->player.plane.y = game()->player.dir.x * FOV_ANGLE;
}
