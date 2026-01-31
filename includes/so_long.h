/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:49:22 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/30 23:07:16 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_properties
{
	void	*img;
	int		width;
	int		height;
}	t_properties;

typedef struct s_textures
{
	t_properties	background;
	t_properties	character;
	t_properties	collectible;
	t_properties	wall;
	t_properties	exit;
}	t_textures;

typedef struct s_state
{
	char		**map;
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	t_textures	texture;
}	t_state;

int		count_line_arq(char **argv, int count_line);
int		close_window(void *param);
int		load_all_texture(t_state *game, t_textures *texture);
void	cleanup_and_exit(t_state *game);
int		ft_init_game(t_state *game, char *map_arq);
int		ft_msg_error(void);

#endif