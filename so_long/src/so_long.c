/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:53:03 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/16 13:18:54 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/so_long.h"

t_canvas	init_canvas(void)
{
	t_canvas canvas;

	canvas.img = (void *)0;
	canvas.addr = (void *)0;
	canvas.bits_per_pixel = 0;
	canvas.line_len = 0;
	canvas.endian = 0;
	return (canvas);
}

void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->addr + (y * canvas->line_len + x * (canvas->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_canvas	canvas;

	mlx = mlx_init();
	canvas = init_canvas();
	win = mlx_new_window(mlx, 400, 160, "so_long");
	canvas.img = mlx_new_image(mlx, 400, 160);
	canvas.addr = mlx_get_data_addr(canvas.img, &canvas.bits_per_pixel, &canvas.line_len, &canvas.endian);
	mlx_put_image_to_window(mlx, win, canvas.img, 0, 0);
	mlx_loop(mlx);
}
