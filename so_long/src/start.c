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

void    start_game(t_canvas *cvs)
{
    void		*mlx;
	void		*win;

    mlx = mlx_init();
	win = mlx_new_window(mlx, (cvs->max_x + 1) * PIXEL, (cvs->max_y + 1) * PIXEL, "so_long");
	cvs->img = mlx_new_image(mlx, 1920, 1080);
	cvs->addr = mlx_get_data_addr(cvs->img, cvs->bpp, cvs->line_len, cvs->endian);
	mlx_put_image_to_window(mlx, win, cvs->img, 0, 0);
}