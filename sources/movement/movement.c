/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/20 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_key(int key)
{
	return (key == XK_w || key == XK_s || key == XK_a || key == XK_d);
}

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

int check_key(int keysym)
{
	if (keysym == XK_Escape)
		kill_all();
	if (is_key(keysym))
		do_key(keysym);
	return (0);
}
