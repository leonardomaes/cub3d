/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2024/07/11 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_map(void)
{
	int	i;
	int	j;

	i = 0;
	printf("------------FILE---------------\n");
	while (game()->map->layout[i])
		printf("%s", game()->map->layout[i++]);
	printf("------------END---------------\n");
	printf("------------MAP---------------\n");
	i = 0;
	while (game()->map->int_map[i])
	{
		j = 0;
		while (game()->map->int_map[i][j])
		{
			printf("%d", game()->map->int_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	
	printf("------------END---------------\n");
	printf("\n");
	printf("C: %d\n", game()->map->texture->ceiling);
	printf("F: %d\n", game()->map->texture->floor);
	printf("NO:%s\n", game()->map->texture->no_path);
	printf("SO:%s\n", game()->map->texture->so_path);
	printf("EA:%s\n", game()->map->texture->ea_path);
	printf("WE:%s\n", game()->map->texture->we_path);
	printf("Offset X:%f\n", game()->map->offset_x);
	printf("Offset Y:%f\n", game()->map->offset_y);
	printf("Height Y:%d\n", game()->map->max_y);
	printf("Width  X:%d\n", game()->map->max_x);

	printf("------------PLAYER-------------\n");
	printf("Player X:%f\n", game()->player.pos.x);
	printf("Player Y:%f\n", game()->player.pos.y);
	printf("Player Rotation:%f\n", game()->player.rotation);
	printf("CamX: %f\n", game()->player.plane.x);
	printf("CamY: %f\n", game()->player.plane.y);
	printf("\n");
}
