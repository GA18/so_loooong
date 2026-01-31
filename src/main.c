/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:42:12 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/31 15:52:47 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_state	game;

	if (argc < 2)
		return (ft_msg_error());
	// if (!ft_init_game(&game, argv[1]))
	// 	return (ft_msg_error());
	count_row_and_col_arq(argv, &game);
	ft_printf("\n%i, %i", game.height, game.width);
	//mlx_loop(game.mlx);
	return (0);
}
