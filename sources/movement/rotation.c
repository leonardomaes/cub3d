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
	double	temp;

	if (key == XK_Right)
	{
		game()->player.rotation -= ROTATION_SPEED;
		if (player(ROT) < 1)
			game()->player.rotation += 360;
	}
	if (key == XK_Left)
	{
		game()->player.rotation += ROTATION_SPEED;
		if (player(ROT) > 360)
			game()->player.rotation -= 360;
	}
	game()->player.dir.y = -sin(get_radian(game()->player.rotation));
	game()->player.dir.x = cos(get_radian(game()->player.rotation));
}


