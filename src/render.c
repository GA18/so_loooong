/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:35:45 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/31 22:56:18 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	load_texture(void *mlx, char *path, t_properties *prop_img)
{
	prop_img->img = mlx_xpm_file_to_image(mlx, path, &prop_img->width,
			&prop_img->height);
	if (!(prop_img->img != NULL))
		exit(1);
}

int	load_all_texture(t_state *game, t_textures *texture)
{
	load_texture(game->mlx, "sprites/background.xpm", &texture->background);
	load_texture(game->mlx, "sprites/character.xpm", &texture->character);
	load_texture(game->mlx, "sprites/collectible.xpm", &texture->collectible);
	load_texture(game->mlx, "sprites/exit.xpm", &texture->exit);
	load_texture(game->mlx, "sprites/wall.xpm", &texture->wall);
	return (1);
}

int	render_map(t_state *game, t_properties prop, char *arq_map)
{
	int	load;

	(void)arq_map;
	load = mlx_put_image_to_window(game->mlx, game->win, prop.img, 0, 0);
	if (!load)
		return (0);
	return (1);
}

