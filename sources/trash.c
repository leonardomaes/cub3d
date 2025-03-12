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

#include "../includes/cub3d.h"

void	print_map(void)
{
	int	i;

	i = 0;
	printf("------------FILE---------------\n");
	while (game()->map->layout[i])
		printf("%s", game()->map->layout[i++]);
	printf("------------END---------------\n");
	printf("\n");
	printf("Ceiling:%s\n", game()->map->texture->ceiling_color);
	printf("Floor:%s\n", game()->map->texture->floor_color);
	printf("NO:%s\n", game()->map->texture->no_path);
	printf("SO:%s\n", game()->map->texture->so_path);
	printf("EA:%s\n", game()->map->texture->ea_path);
	printf("WE:%s\n", game()->map->texture->we_path);
	printf("\n");
	
}
