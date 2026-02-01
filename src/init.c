/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:45:56 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/01 16:23:09 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_define_window(t_state *game, char *arq_map);
static int	ft_init_state(t_state *game);
static int	ft_init_mlx(t_state *game);
static int	ft_init_map(t_state *game, char *arq_map);

int	ft_init_game(t_state *game, char *arq_map)
{

	ft_init_state(game);
	ft_define_window(game, arq_map);
	ft_init_map(game, arq_map);
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
	return (0);
}

static int	ft_define_window(t_state *game, char *arq_map)
{
	parser_and_validate_map(arq_map, game);
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
	//cleanup_and_exit(game);
	return (0);
}

int	ft_init_map(t_state *game, char *arq_map)
{
	int		fd;
	int		index_y;
	char	*line;

	fd = open(arq_map, O_RDONLY);
	line = get_next_line(fd);
	index_y = 0;
	game->map = malloc(game->height * sizeof(char *));
	game->map[index_y] = malloc(game->width * sizeof(char));
	ft_memcpy(game->map[index_y], line, (size_t)game->width);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			index_y++;
			game->map[index_y] = malloc(((game->width + 1) * sizeof(char)));
			ft_memcpy(game->map[index_y], line, (size_t)game->width);
		}
		game->map[index_y][game->width] = '\0';

	}
	close(fd);
	return (0);
}
