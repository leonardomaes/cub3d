/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/11 19:19:52 by rda-cunh         ###   ########.fr       */
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


int	handle_mouse_move(int x, int y, void *param)
{
	static int	prev_x;
	int		delta;
	double	angle;

	(void)y;
	(void)param;
	//assign prev_x as the center of the screen
	prev_x = WINDOW_WIDTH / 2;

	//calculate the delta value (mouse movement)
	delta = x - prev_x;

	//rotates if there is a movement
	if (delta != 0)
	{
		//the rotation is based of the value of delta and adjusted with the MOUSE_SENSIBILITY (macro)
		game()->player.rotation -= delta * MOUSE_SENSIBILITY;
		//doing the mormalization of the angle (like in rotate_key)
		if (game()->player.rotation < 1)
			game()->player.rotation += 360;
		else if (game()->player.rotation > 360)
			game()->player.rotation -= 360;
		//updating the direction vector
		angle = get_radian(game()->player.rotation);
		game()->player.dir.x = cos(angle);
		game()->player.dir.y = -sin(angle);
		//updating the camera vector (perpenticular to direction vector)
		game()->player.plane.x = -game()->player.dir.y * FOV_ANGLE;
		game()->player.plane.y = game()->player.dir.x * FOV_ANGLE;
	}

	//center the mouse cursor in the window (this is optional) - to check if this works of or not
	mlx_mouse_move(game()->mlx->mlx, game()->mlx->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		prev_x = WINDOW_WIDTH / 2;
	return (0);
}
