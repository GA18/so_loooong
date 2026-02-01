/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:45:56 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/31 22:55:32 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_game(t_state *game, char *arq_map)
{
	ft_bzero(game, sizeof(t_state));
	game->texture.character.tile = 'P';
	game->texture.collectible.tile = 'C';
	game->texture.exit.tile = 'E';
	game->texture.wall.tile = '1';
	game->texture.background.tile = '0';
	game->texture.character.quantity = 0;
	game->texture.collectible.quantity = 0;
	game->texture.exit.quantity = 0;
	count_row_and_col_arq(arq_map, game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, 1000, 1000, "so_long");
	if (!game->win)
		return (0);
	mlx_hook(game->win, 17, 0, close_window, &game);
	if (!load_all_texture(game, &game->texture))
		ft_msg_error(); //cleanup_and_exit(game);
	if (!render_map(game, game->texture.wall, arq_map))
		ft_msg_error(); //cleanup_and_exit(game);
	return (1);
}
