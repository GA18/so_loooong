/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:23:44 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/04 12:42:50 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_player(t_state *game, t_textures *t, int pos_x, int pos_y);

int	keyboard_press(int keycode, t_state *game)
{
	if (keycode == KEY_ESC)
		cleanup_and_exit("", game);
	if (keycode == KEY_W)
		ft_move_player(game, &game->texture, 0, -1);
	if (keycode == KEY_S)
		ft_move_player(game, &game->texture, 0, 1);
	if (keycode == KEY_A)
		ft_move_player(game, &game->texture, -1, 0);
	if (keycode == KEY_D)
		ft_move_player(game, &game->texture, 1, 0);
	return (1);
}

static void	ft_move_player(t_state *game, t_textures *t, int p_x, int p_y)
{
	if (game->map[t->character.y + p_y][t->character.x + p_x]
		== t->collectible.tile)
		t->collectible.quantity--;
	if (game->map[t->character.y + p_y][t->character.x + p_x]
		== t->exit.tile && t->collectible.quantity == 0)
		cleanup_and_exit("Parabéns! Você finalizou o game!", game);
	if (game->map[t->character.y + p_y][t->character.x + p_x]
		== t->exit.tile && t->collectible.quantity != 0)
		ft_printf("Colete todos os itens antes de sair\n");
	if (game->map[t->character.y + p_y][t->character.x + p_x] != t->wall.tile
	&& game->map[t->character.y + p_y][t->character.x + p_x] != t->exit.tile)
	{
		game->map[t->character.y][t->character.x] = t->background.tile;
		define_render_texture(game, t, t->character.y, t->character.x);
		t->character.x += p_x;
		t->character.y += p_y;
		game->map[t->character.y][t->character.x] = t->character.tile;
		define_render_texture(game, t, t->character.y, t->character.x);
		ft_printf("Movimento de número: %i\n", t->character.quantity++);
	}
}
