/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:24:33 by g-alves-          #+#    #+#             */
/*   Updated: 2026/01/28 18:06:54 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line_arq(char **argv, int count_line)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf(line);
		count_line++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count_line);
}

int	close_window(void *param)
{
	t_state	*game;

	game = (t_state *)param;
	exit(0);
}
