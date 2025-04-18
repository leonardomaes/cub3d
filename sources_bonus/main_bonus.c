/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:52:08 by lmaes             #+#    #+#             */
/*   Updated: 2024/07/11 12:52:10 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_cub	*game(void)
{
	static t_cub	game;

	return (&game);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		init_mlx(game(), argv[1]);
		file_check();
		load_texture();
		setup_hook();
	}
	else
	{
		ft_printf("ERROR:Wrong number of arguments!\n");
		exit(1);
	}
	clear_all();
	return (0);
}
