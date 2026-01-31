/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:35:45 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/31 15:03:39 by g-alves-         ###   ########.fr       */
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

// render_map(t_state *game, t_properties *prop_img, char *map_arq)
// {
	
// }
// char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
// 			   int *size_line, int *endian);
