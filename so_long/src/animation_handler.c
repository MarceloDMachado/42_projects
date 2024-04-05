/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:38:02 by madias-m          #+#    #+#             */
/*   Updated: 2024/04/02 17:38:07 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	collectible(t_canvas *c, int pixel)
{
	static char	state;

	mlx_destroy_image(c->mlx, c->sprites.collectible);
	if (state == 0)
		c->sprites.collectible = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/collectible_a.xpm", &pixel, &pixel);
	else if (state == 1)
		c->sprites.collectible = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/collectible_b.xpm", &pixel, &pixel);
	else if (state == 2)
		c->sprites.collectible = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/collectible_c.xpm", &pixel, &pixel);
	else if (state == 3)
	{
		c->sprites.collectible = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/collectible_d.xpm", &pixel, &pixel);
		state = 0;
		return ;
	}
	state++;
}

void	enemy(t_canvas *c, int pixel)
{
	static char	state;

	mlx_destroy_image(c->mlx, c->sprites.enemy);
	if (state == 0)
		c->sprites.enemy = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/enemy_a.xpm", &pixel, &pixel);
	else if (state == 1)
		c->sprites.enemy = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/enemy_b.xpm", &pixel, &pixel);
	else if (state == 2)
		c->sprites.enemy = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/enemy_c.xpm", &pixel, &pixel);
	else if (state == 3)
	{
		c->sprites.enemy = mlx_xpm_file_to_image(c->mlx, \
		"./sprites/enemy_d.xpm", &pixel, &pixel);
		state = 0;
		return ;
	}
	state++;
}

int animate(void *ptr)
{
    static int  count;
    t_canvas    *cvs;

    ft_printf("count: %d\n", count);
    cvs = ptr;
    if (count == 1000)
        collectible(cvs, PIXEL);
    else if (count == 1300)
    {
        enemy(cvs, PIXEL);
        count = 0;
        return (1);
    }
    count++;
    return (1);
}
