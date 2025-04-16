/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/04/16 19:28:44 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_split(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}

void	free_texture_split(int **data)
{
	int	i;

	i = 0;
	while (i < game()->map->texture->height)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

void	clear_mlx(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx);
}
