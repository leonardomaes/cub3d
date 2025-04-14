/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/15 00:21:07 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_key(int key)
{
	return (key == XK_w || key == XK_s || key == XK_a || key == XK_d
		|| key == XK_Left || key == XK_Right);
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
	move_key(key);
	rotate_key(key);
}

int	check_key(int keysym)
{
	if (keysym == XK_Escape)
		kill_all();
	if (is_key(keysym))
		do_key(keysym);
	return (0);
}
