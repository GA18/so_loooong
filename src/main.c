/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:42:12 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/28 18:07:29 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_state	game;

	if (argc < 2)
		return (0);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	game.win = mlx_new_window(game.mlx, 500, 500, "so_long");
	if (!game.win)
		return (0);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 0, close_window, &game);
	mlx_loop(game.mlx);
	ft_printf("\nO arquivo tem %i linhas", count_line_arq(argv, 0));
}
