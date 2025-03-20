/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2025/03/20 19:08:29 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cub	*game(void)
{
	static t_cub	game;

	return (&game);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		init_game(game(), argv[1]);
		file_check();
		// load();
		print_map();
		setup_hook();
		draw_minimap(game());
	}
	else
	{
		ft_printf("ERROR:Wrong number of arguments!\n");
		exit(1);
	}
	clear_all();
	return (0);
}
