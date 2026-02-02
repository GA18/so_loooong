/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:24:33 by g-alves-          #+#    #+#             */
/*   Updated: 2026/02/02 18:59:14 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	t_state	*game;

	game = (t_state *)param;
	cleanup_and_exit("Obrigado por jogar Yu-gi-oh! So_looong!!!", game);
	return (0);
}

// int	key_esc(void *param)
// {
// 	if ()
// }

int	ft_strlen_line(const char *s)
{
	int		length;

	length = 0;
	while (*s && *s != '\n')
	{
			length++;
		s++;
	}
	return (length);
}
