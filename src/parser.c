/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:17:43 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/02 18:06:49 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	valid_content(t_state *game, t_textures *elements);
static void	valid_border(t_state *game, t_textures *elements);
//static void	valid_line(t_state *game);

void	parser_controller(char *arq_map, t_state *game)
{
	read_map(arq_map, game);
	game->map = ft_init_map(arq_map, game->height, game->width);
	//valid_line(game);
	valid_border(game, &game->texture);
	valid_content(game, &game->texture);
	if (game->texture.character.quantity != 1
		|| game->texture.exit.quantity != 1
		|| game->texture.collectible.quantity < 1)
		cleanup_and_exit("Only 1 player, 1 exit, and at least 1 collectible.",
			game);
}

void	read_map(char *arq_map, t_state *game)
{
	int		fd;
	char	*line;

	fd = open(arq_map, O_RDONLY);
	if (fd < 0)
		cleanup_and_exit("Invalid FD", game);
	line = get_next_line(fd);
	if (!line)
		cleanup_and_exit("Error GNL", game);
	game->width = ft_strlen_line(line);
	while (line)
	{
		if (game->width != ft_strlen_line(line))
		{
			free(line);
			get_next_line(-1);
			close(fd);
			cleanup_and_exit("All columns must be the same length.", game);
		}
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

// static void	valid_line(t_state *game)
// {
// 	int	y;

// 	y = 0;
// 	while (y < game->height)
// 	{
// 		if (!(ft_strlen_line(game->map[y]) == game->width))
// 			cleanup_and_exit(game);
// 		y++;
// 	}
// }

static void	valid_border(t_state *game, t_textures *elements)
{
	int	x;

	x = 0;
	while (x < game->width)
	{
		if (!(game->map[0][x] == elements->wall.tile))
			cleanup_and_exit("Border top must only wall", game);
		if (!(game->map[game->height - 1][x] == elements->wall.tile))
			cleanup_and_exit("Border Down must only wall", game);
		x++;
	}
}

static void	valid_content(t_state *game, t_textures *elements)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == elements->character.tile)
				elements->character.quantity++;
			else if (game->map[y][x] == elements->exit.tile)
				elements->exit.quantity++;
			else if (game->map[y][x] == elements->collectible.tile)
				elements->collectible.quantity++;
			else if (!(game->map[y][x] == elements->wall.tile
				|| game->map[y][x] == elements->background.tile))
				cleanup_and_exit("Your map don't have any invalid char", game);
			x++;
		}
		y++;
	}
}
