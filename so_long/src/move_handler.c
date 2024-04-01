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

	p_pos = get_element_pos(cvs->map, 'P');
	if (cvs->map[p_pos.y + y][p_pos.x + x] == '1')
		return ;
	cvs->player_moves++;
	if (ft_strchr("C0", cvs->map[p_pos.y + y][p_pos.x + x]))
	{
		if (cvs->map[p_pos.y + y][p_pos.x + x] == 'C')
			cvs->collectables_count++;
		cvs->map[p_pos.y + y][p_pos.x + x] = 'P';
		cvs->map[p_pos.y][p_pos.x] = '0';
		render(cvs);
	}
	else if (cvs->map[p_pos.y + y][p_pos.x + x] == 'K')
	{
		ft_printf("game over...");
		quit_game(cvs, EXIT_FAILURE);
	}
	else if (cvs->map[p_pos.y + y][p_pos.x + x] == 'E')
	{
		ft_printf("you won!");
		quit_game(cvs, EXIT_SUCCESS);
	}
}

void	move_player(int key, t_canvas *cvs)
{
	char	*move_count;

	move_count = ft_itoa((cvs->player_moves));
	mlx_string_put(cvs->mlx, cvs->win, 48, 48, 0x42f593, move_count);
	if (key == 'w' || key == UP)
		move(cvs, -1, 0);
	else if (key == 's' || key == DOWN)
		move(cvs, 1, 0);
	else if (key == 'd' || key == RIGHT)
		move(cvs, 0, 1);
	else if (key == 'a' || key == LEFT)
		move(cvs, 0, -1);
	free(move_count);
}
