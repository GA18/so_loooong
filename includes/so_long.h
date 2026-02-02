/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:49:22 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/02 17:57:06 by g-alves-         ###   ########.fr       */
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

# define TILE_SIZE 64

typedef struct s_properties
{
	void	*img;
	int		width;
	int		height;
	int		y;
	int		x;
	int		quantity;
	char	tile;
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

void	parser_controller(char *arq_map, t_state *game);
void	read_map(char *arq_map, t_state *game);
int		close_window(void *param);
void	cleanup_and_exit(char *msg_error, t_state *game);
int		ft_init_game(t_state *game, char *arq_map);
int		ft_msg_error(void);
int		ft_strlen_line(const char *s);
void	valid_map(char *line, t_textures *elements, int borders, int border_c);
int		render_map(t_state *game);
int		ft_load_and_render(t_state *game);
int		define_render_texture(t_state *game, t_textures *texture, int y, int x);
char	**ft_init_map(char *file, int height, int width);
int		controller_flood(char *arq_map, t_state *game);

#endif