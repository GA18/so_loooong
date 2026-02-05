/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:45:56 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/04 19:28:43 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_init_state(t_state *game);
static int	ft_init_mlx(t_state *game);

int	ft_init_game(t_state *game, char *arq_map)
{
	ft_init_state(game);
	parser_controller(arq_map, game);
	controller_flood(arq_map, game);
	ft_init_mlx(game);
	ft_load_and_render(game);
	return (1);
}

static int	ft_init_state(t_state *game)
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
	game->texture.character.quantity = 0;
	return (0);
}

static int	ft_init_mlx(t_state *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, (game->width * TILE_SIZE),
			(game->height * TILE_SIZE), "so_long");
	if (!game->win)
		return (0);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_hook(game->win, 2, 1, keyboard_press, game);
	return (0);
}

char	**ft_init_map(char *file, int height, int width)
{
	int		fd;
	int		index_y;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	index_y = 0;
	map = malloc((height) * sizeof(char *));
	if (!map)
		return (NULL);
	while (index_y < height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[index_y] = malloc(((width + 1) * sizeof(char)));
		ft_memcpy(map[index_y], line, (size_t)width);
		map[index_y++][width] = '\0';
		free(line);
	}
	get_next_line (-1);
	close(fd);
	return (map);
}
