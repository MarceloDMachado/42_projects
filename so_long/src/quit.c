/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:46:15 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/28 20:46:17 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void free_sprites(t_canvas *cvs)
{
	mlx_destroy_image(cvs->mlx, cvs->sprites.wall);
	mlx_destroy_image(cvs->mlx, cvs->sprites.floor);
	mlx_destroy_image(cvs->mlx, cvs->sprites.player_r);
	mlx_destroy_image(cvs->mlx, cvs->sprites.player_l);
	mlx_destroy_image(cvs->mlx, cvs->sprites.enemy);
	mlx_destroy_image(cvs->mlx, cvs->sprites.collectable);
	mlx_destroy_image(cvs->mlx, cvs->sprites.exit);
}

void	quit_game(t_canvas *cvs)
{
	free_sprites(cvs);
	free_map(cvs);
	mlx_destroy_window(cvs->mlx, cvs->win);
	mlx_destroy_display(cvs->mlx);
	free(cvs->mlx);
	exit(EXIT_FAILURE);
}