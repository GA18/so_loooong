/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:17:43 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/01 19:31:26 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	valid_content(char *line, t_textures *elements);
static void	valid_border(char *line, t_textures *elements, int width);
static void	valid_quantity(t_textures *elements);

void	parser_and_validate_map(char *arq_map, t_state *game)
{
	int		fd;
	char	*line;

	fd = open(arq_map, O_RDONLY);
	if (!fd)
		ft_msg_error();
	line = get_next_line(fd);
	game->width = ft_strlen_line(line);
	while (line)
	{
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	valid_quantity(&game->texture);
}

void	valid_map(char *line, t_textures *elements, int borders, int border_c)
{

	if (line[0] != elements->wall.tile
		|| line[border_c] != elements->wall.tile)
		ft_msg_error();
	if (borders == 0)
		valid_border(line, elements, border_c);
	if (borders != 0)
		valid_content(line, elements);
}

static void	valid_border(char *line, t_textures *elements, int width)
{
	int	index;

	index = 0;
	while (index < width)
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
