/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:35:45 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/29 23:35:20 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	load_texture(void *mlx, char *path, t_properties *prop_img)
{
	prop_img->img = mlx_xpm_file_to_image(mlx, path, prop_img->width,
			prop_img->height);
	if (!(prop_img != NULL))
		exit(1);
}

void	render_window(void *mlx, t_textures *texture)
{
	load_texture(mlx, "sprites/background.xpm", &texture->background);
	load_texture(mlx, "sprites/character.xpm", &texture->character);
	load_texture(mlx, "sprites/collectible.xpm", &texture->collectible);
	load_texture(mlx, "sprites/exit.xpm", &texture->exit);
	load_texture(mlx, "sprites/wall.xpm", &texture->wall);

}

// int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
// 				int x, int y);