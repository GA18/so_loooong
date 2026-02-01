/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:39:57 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/01 16:19:02 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	destroy_texture(void *mlx, t_textures *texture);
static	void	free_map(t_state *game);
static	void	free_mlx(t_state *game);

void	cleanup_and_exit(t_state *game)
{
	destroy_texture(game->mlx, &game->texture);
	free_map(game);
	free_mlx(game);
	exit (1);
}

int	ft_msg_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

static	void	destroy_texture(void *mlx, t_textures *texture)
{
	if (texture->background.img)
		mlx_destroy_image(mlx, texture->background.img);
	if (texture->character.img)
		mlx_destroy_image(mlx, texture->character.img);
	if (texture->collectible.img)
		mlx_destroy_image(mlx, texture->collectible.img);
	if (texture->exit.img)
		mlx_destroy_image(mlx, texture->exit.img);
	if (texture->wall.img)
		mlx_destroy_image(mlx, texture->wall.img);
	texture->background.img = NULL;
	texture->character.img = NULL;
	texture->collectible.img = NULL;
	texture->exit.img = NULL;
	texture->wall.img = NULL;
}

static	void	free_map(t_state *game)
{
	int	y;

	y = 0;
	while (y < game->height)
		free(game->map[y++]);
	free(game->map);
}

static	void	free_mlx(t_state *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
