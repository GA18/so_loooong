/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 08:29:50 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/03 23:05:03 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_textures *t, char **visit_map, int y, int x);

int	controller_flood(char *arq_map, t_state *game)
{
	char	**visited_map;
	int		index;

	visited_map = ft_init_map(arq_map, game->height, game->width);
	find_point(game->map, &game->texture.character);
	index = 0;
	game->texture.collectible.rest = game->texture.collectible.quantity;
	flood_fill(&game->texture, visited_map, game->texture.character.y,
		game->texture.character.x);
	if (game->texture.collectible.rest > 0
		|| game->texture.exit.accessible != 1)
	{
		while (index < game->height)
			free(visited_map[index++]);
		free(visited_map);
		cleanup_and_exit("Invalid map, don't have valid path", game);
	}
	while (index < game->height)
		free(visited_map[index++]);
	free(visited_map);
	return (0);
}

int	find_point(char **map, t_properties *player)
{
	player->y = 0;
	while (map[player->y])
	{
		player->x = 0;
		while (map[player->y][player->x])
		{
			if (map[player->y][player->x] == player->tile)
				return (map[player->y][player->x]);
			player->x++;
		}
		player->y++;
	}
	return (0);
}

static void	flood_fill(t_textures *t, char **visit_map, int y, int x)
{
	if (visit_map[y][x] == t->wall.tile || visit_map[y][x] == 'V'
		|| (t->exit.accessible == 1 && t->collectible.rest > 0))
		return ;
	if (visit_map[y][x] == t->collectible.tile)
		t->collectible.rest--;
	if (visit_map[y][x] == t->exit.tile)
		t->exit.accessible = 1;
	if (visit_map[y][x] != t->exit.tile)
		visit_map[y][x] = 'V';
	flood_fill (t, visit_map, (y + 1), x);
	flood_fill (t, visit_map, (y - 1), x);
	flood_fill (t, visit_map, y, (x + 1));
	flood_fill (t, visit_map, y, (x - 1));
}
