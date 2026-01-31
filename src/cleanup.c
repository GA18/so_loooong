/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:39:57 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/31 15:09:52 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	free_texture(void *mlx, t_textures *texture);
static	void	free_map(char **map);
static	void	free_mlx(t_state *game);

void	cleanup_and_exit(t_state *game)
{
	free_texture(game->mlx, &game->texture);
	free_map(game->map);
	free_mlx(game);
}

int	ft_msg_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

static	void	free_texture(void *mlx, t_textures *texture)
{
	if (texture->background.img)
		mlx_destroy_image(mlx, texture->background.img);
	if (texture->character.img)
		mlx_destroy_image(mlx, texture->character.img);
	if (texture->collectible.img)
		mlx_destroy_image(mlx, texture->collectible.img);
	if (texture->exit.img)
		mlx_destroy_image(mlx, texture->exit.img);
	if (texture->character.img)
		mlx_destroy_image(mlx, texture->wall.img);
}

static	void	free_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if (map)
	{
		while (map[x][y])
		{
			while (map[x][y])
			{
				free(&map[x][y]);
				x++;
			}
			y++;
			x = 0;
		}
	}
}

static	void	free_mlx(t_state *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
}
