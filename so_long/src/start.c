/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:58:20 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/28 17:58:21 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_sprites(t_canvas *c, int pixel)
{
	c->sprites.floor = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/floor.xpm", &pixel, &pixel);
	c->sprites.enemy = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/enemy.xpm", &pixel, &pixel);
	c->sprites.player_l = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/player_l.xpm", &pixel, &pixel);
	c->sprites.player_r = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/player_r.xpm", &pixel, &pixel);
	c->sprites.collectable = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/collectable.xpm", &pixel, &pixel);
	c->sprites.exit = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/exit.xpm", &pixel, &pixel);
	c->sprites.wall = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/wall.xpm", &pixel, &pixel);
}

void	start_game(t_canvas *cvs)
{
	void	*win;

	cvs->mlx = mlx_init();
	cvs->win = mlx_new_window(cvs->mlx, (cvs->max_x + 1) * PIXEL, \
		(cvs->max_y + 1) * PIXEL, "so_long");
	set_sprites(cvs, PIXEL);
	mlx_expose_hook(cvs->win, &render, cvs);
	mlx_loop(cvs->mlx);
}
