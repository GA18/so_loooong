/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:45:56 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/31 15:04:20 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_init_game(t_state *game, char *map_arq)
// {
// 	ft_bzero(game, sizeof(t_state));
// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		return (0);
// 	game->win = mlx_new_window(game->mlx, 1000, 1000, "so_long");
// 	if (!game->win)
// 		return (0);
// 	mlx_hook(game->win, 17, 0, close_window, &game);
// 	if (!load_all_texture(game, &game->texture))
// 		cleanup_and_exit(game);
// 	if (!render_map(game, &game->texture, &map_arq))
// 		cleanup_and_exit(game);
// 	count_line_arq(&map_arq, 0);
// 	return (1);
// }
