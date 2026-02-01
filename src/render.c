/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:35:45 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/01 15:06:39 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		load_texture(void *mlx, char *path, t_properties *prop_img);
static int		load_all_texture(t_state *game, t_textures *texture);


static	void	load_texture(void *mlx, char *path, t_properties *prop_img)
{
	prop_img->img = mlx_xpm_file_to_image(mlx, path, &prop_img->width,
			&prop_img->height);
	if (!(prop_img->img != NULL))
		exit(1);
}

static int	load_all_texture(t_state *game, t_textures *texture)
{
	load_texture(game->mlx, "sprites/background.xpm", &texture->background);
	load_texture(game->mlx, "sprites/character.xpm", &texture->character);
	load_texture(game->mlx, "sprites/collectible.xpm", &texture->collectible);
	load_texture(game->mlx, "sprites/exit.xpm", &texture->exit);
	load_texture(game->mlx, "sprites/wall.xpm", &texture->wall);
	return (1);
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
	return (1);
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
	if (!load_all_texture(game, &game->texture))
		ft_msg_error(); //cleanup_and_exit(game);
	if (!render_map(game))
		ft_msg_error(); //cleanup_and_exit(game);
	return (0);
}

