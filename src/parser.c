/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:17:43 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/31 22:38:14 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	valid_content(char *line, t_textures *elements);
static void	valid_border(char *line, t_textures *elements);
static void	valid_quantity(t_textures *elements);

int	count_row_and_col_arq(char *arq_map, t_state *game)
{
	int		fd;
	char	*line;
	char	*last_line;

	fd = open(arq_map, O_RDONLY);
	line = get_next_line(fd);
	game->width = ft_strlen_line(line);
	valid_map(line, &game->texture, 0);
	while (line)
	{
		game->height++;
		last_line = line;
		line = get_next_line(fd);
		if (line && (int)ft_strlen_line(line) != game->width)
			ft_msg_error();
		if (line)
			valid_map(line, &game->texture, game->height);
	}
	close(fd);
	if (last_line)
		valid_map(last_line, &game->texture, 0);
	valid_quantity(&game->texture);
	return (0);
}

void	valid_map(char *line, t_textures *elements, int borders)
{
	if (line[0] != elements->wall.tile
		|| line[ft_strlen_line(line) - 1] != elements->wall.tile)
		ft_msg_error();
	if (borders == 0)
		valid_border(line, elements);
	if (borders != 0)
		valid_content(line, elements);
}

static void	valid_border(char *line, t_textures *elements)
{
	int	index;

	index = 0;
	while (index < ft_strlen_line(line) - 1)
		if (line[index++] != elements->wall.tile)
			ft_msg_error();
}

static void	valid_content(char *line, t_textures *elements)
{
	int	index;

	index = 0;
	while (line[index] && line[index] != '\n')
	{
		if (line[index] == elements->character.tile)
			elements->character.quantity++;
		if (line[index] == elements->exit.tile)
			elements->exit.quantity++;
		if (line[index] == elements->collectible.tile)
			elements->collectible.quantity++;
		if (line[index] != elements->character.tile
			&& line[index] != elements->collectible.tile
			&& line[index] != elements->wall.tile
			&& line[index] != elements->exit.tile
			&& line[index] != elements->background.tile)
			ft_msg_error();
		index++;
	}
}

static void	valid_quantity(t_textures *elements)
{
	if (elements->character.quantity != 1
		|| elements->exit.quantity != 1
		|| elements->collectible.quantity < 1)
		ft_msg_error();
}
