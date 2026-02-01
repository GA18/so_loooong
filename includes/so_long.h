/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:49:22 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/31 22:53:09 by g-alves-         ###   ########.fr       */
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

int		count_row_and_col_arq(char *arq_map, t_state *game);
int		close_window(void *param);
int		load_all_texture(t_state *game, t_textures *texture);
void	cleanup_and_exit(t_state *game);
int		ft_init_game(t_state *game, char *arq_map);
int		ft_msg_error(void);
int		ft_strlen_line(const char *s);
void	valid_map(char *line, t_textures *elements, int borders);
int		render_map(t_state *game, t_properties prop, char *arq_map);

#endif