/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:55:45 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/28 20:56:15 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move(t_canvas *cvs, int y, int x)
{
	t_coord	p_pos;
	char	*destiny;

	p_pos = get_element_pos(cvs->map, 'P');
	destiny = &(cvs->map[p_pos.y + y][p_pos.x + x]);
	if (*destiny == '1')
		return ;
	cvs->player_moves++;
	if (ft_strchr("C0", *destiny))
	{
		if (*destiny == 'C')
			cvs->collectibles_count--;
		*destiny = 'P';
		cvs->map[p_pos.y][p_pos.x] = '0';
		render(cvs);
	}
	else if (*destiny == 'K')
	{
		ft_printf("game over...");
		quit_game(cvs, EXIT_FAILURE);
	}
	else if (*destiny == 'E' && !cvs->collectibles_count)
	{
		ft_printf("you won!");
		quit_game(cvs, EXIT_SUCCESS);
	}
}

void	move_player(int key, t_canvas *cvs)
{
	if (key == 'w' || key == UP)
		move(cvs, -1, 0);
	else if (key == 's' || key == DOWN)
		move(cvs, 1, 0);
	else if (key == 'd' || key == RIGHT)
	{
		cvs->player_dir = 'r';
		move(cvs, 0, 1);
	}
	else if (key == 'a' || key == LEFT)
	{
		cvs->player_dir = 'l';
		move(cvs, 0, -1);
	}
}
