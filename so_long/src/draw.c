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

#include "../includes/so_long.h"

static	void	put_wall(t_canvas *cvs, int y, int x)
{
	if (y == cvs->max_y)
		put_sprite(cvs, y, x, cvs->sprites.trail);
	else
		put_sprite(cvs, y, x, cvs->sprites.wall);
}

static	void	put_player(t_canvas *cvs, int y, int x)
{
	if (cvs->player_dir == 'r')
		put_sprite(cvs, y, x, cvs->sprites.player_r);
	else
		put_sprite(cvs, y, x, cvs->sprites.player_l);
}

static	void	draw_pos(t_canvas *cvs, int y, int x)
{
	if (cvs->map[y][x] == '1')
		put_wall(cvs, y, x);
	else if (cvs->map[y][x] == '0')
		put_sprite(cvs, y, x, cvs->sprites.floor);
	else if (cvs->map[y][x] == 'P')
		put_player(cvs, y, x);
	else if (cvs->map[y][x] == 'C')
		put_sprite(cvs, y, x, cvs->sprites.collectible);
	else if (cvs->map[y][x] == 'K')
		put_sprite(cvs, y, x, cvs->sprites.enemy);
	else if (cvs->map[y][x] == 'E')
		put_sprite(cvs, y, x, cvs->sprites.exit);
}

int	render(t_canvas *cvs)
{
	int		y;
	int		x;
	char	*move_count;

	y = 0;
	while (cvs->map[y])
	{
		x = 0;
		while (cvs->map[y][x])
			draw_pos(cvs, y, x++);
		y++;
	}
	move_count = ft_itoa(cvs->player_moves);
	mlx_string_put(cvs->mlx, cvs->win, 24, 24, 0x42f593, move_count);
	free(move_count);
	return (0);
}
