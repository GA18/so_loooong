/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:17:43 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/31 18:56:14 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_row_and_col_arq(char **argv, t_state *game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	game->width = ft_strlen_line(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line && (int)ft_strlen_line(line) != game->width)
			ft_msg_error();
	}
	close(fd);
	valid_map(argv, game);
	return (0);
}

int	valid_map(char *line, char )
{
	int		fd;
	int		x;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	x = 0;
	while (line)
	{
		if (line[x] == '1')
			x++;
	}
	return (0);
}
