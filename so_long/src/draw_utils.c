/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:47:22 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/28 19:47:24 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_sprite(t_canvas *cvs, int y, int x, void *sprite)
{
	mlx_put_image_to_window(cvs->mlx, cvs->win, sprite, \
		x * PIXEL, y * PIXEL);
}
