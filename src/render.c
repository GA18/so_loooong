/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:35:45 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/02 07:32:24 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		load_texture(void *mlx, char *path, t_properties *prop_img);
static int		load_all_texture(t_state *game, t_textures *texture);


static	int	load_texture(void *mlx, char *path, t_properties *prop_img)
{
	prop_img->img = mlx_xpm_file_to_image(mlx, path, &prop_img->width,
			&prop_img->height);
	if (!(prop_img->img != NULL))
		return (1);
	return (0);
}

static int	load_all_texture(t_state *game, t_textures *texture)
{
	if (load_texture(game->mlx, "sprites/background.xpm", &texture->background))
		cleanup_and_exit(game);
	if (load_texture(game->mlx, "sprites/character.xpm", &texture->character))
		cleanup_and_exit(game);
	if (load_texture(game->mlx, "sprites/collectible.xpm",
			&texture->collectible))
		cleanup_and_exit(game);
	if (load_texture(game->mlx, "sprites/exit.xpm", &texture->exit))
		cleanup_and_exit(game);
	if (load_texture(game->mlx, "sprites/wall.xpm", &texture->wall))
		cleanup_and_exit(game);
	return (0);
}

int	render_map(t_state *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
			x += define_render_texture(game, &game->texture, y, x);
		y++;
	}
	return (0);
}

int	define_render_texture(t_state *game, t_textures *texture, int y, int x)
{
	if (texture->background.tile == game->map[y][x])
		mlx_put_image_to_window(game->mlx, game->win,
			texture->background.img, (x * TILE_SIZE), (y * TILE_SIZE));
	if (texture->character.tile == game->map[y][x])
		mlx_put_image_to_window(game->mlx, game->win,
			texture->character.img, (x * TILE_SIZE), (y * TILE_SIZE));
	if (texture->collectible.tile == game->map[y][x])
		mlx_put_image_to_window(game->mlx, game->win,
			texture->collectible.img, (x * TILE_SIZE), (y * TILE_SIZE));
	if (texture->exit.tile == game->map[y][x])
		mlx_put_image_to_window(game->mlx, game->win,
			texture->exit.img, (x * TILE_SIZE), (y * TILE_SIZE));
	if (texture->wall.tile == game->map[y][x])
		mlx_put_image_to_window(game->mlx, game->win,
			texture->wall.img, (x * TILE_SIZE), (y * TILE_SIZE));
	return (1);
}

int	ft_load_and_render(t_state *game)
{
	if (load_all_texture(game, &game->texture))
		cleanup_and_exit(game);
	if (render_map(game))
		cleanup_and_exit(game);
	return (0);
}

