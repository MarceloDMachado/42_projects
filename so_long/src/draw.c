/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:01:54 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/28 20:01:55 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	draw_pos(t_canvas *cvs, int y, int x)
{
	if (cvs->map[y][x] == '1')
		put_sprite(cvs, y, x, cvs->sprites.wall);
	else if (cvs->map[y][x] == '0')
		put_sprite(cvs, y, x, cvs->sprites.floor);
	else if (cvs->map[y][x] == 'P' && cvs->player_moves % 2 == 0)
		put_sprite(cvs, y, x, cvs->sprites.player_r);
	else if (cvs->map[y][x] == 'P' && cvs->player_moves % 2 == 1)
		put_sprite(cvs, y, x, cvs->sprites.player_l);
	else if (cvs->map[y][x] == 'C')
		put_sprite(cvs, y, x, cvs->sprites.collectable);
	else if (cvs->map[y][x] == 'K')
		put_sprite(cvs, y, x, cvs->sprites.enemy);
	else if (cvs->map[y][x] == 'E')
		put_sprite(cvs, y, x, cvs->sprites.exit);
}

int	render(t_canvas *cvs)
{
	int		y;
	int		x;

	y = 0;
	while (cvs->map[y])
	{
		x = 0;
		while (cvs->map[y][x])
			draw_pos(cvs, y, x++);
		y++;
	}
	return (0);
}
