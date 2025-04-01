/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/13 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* void	render_walls(t_ray *ray, int x)
{

} */

void	draw_line(double x, double y, t_pos dir)
{
	int	i;

	i = 0;
	while (i++ < (MAP_SCALE * 100))
	{
		my_mlx_pixel_put(game(), x, y, RED_PIXEL);
		x += dir.x;
		y += dir.y;
	}
}

double	get_radian(int angle)
{
	double	radian;

	radian = angle * (PI / 180);
	return (radian);
}


void	load(void)
{
	
}