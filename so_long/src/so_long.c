/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:53:03 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/21 18:51:31 by madias-m         ###   ########.fr       */
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
	canvas.map = (void *)0;
	canvas.max_x = 0;
	canvas.max_y = 0;
	return (canvas);
}

void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->addr + (y * canvas->line_len + x * (canvas->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char**argv)
{
	void		*mlx;
	void		*win;
	t_canvas	canvas;

	if (argc != 2)
		ft_printf("Error\nInvalid args count!");
	if (!ft_strrchr(argv[1], '.') && !ft_memcmp(ft_strrchr(argv[1], '.'), ".ber", 4))
		ft_printf("Error\nInvalid file extension!");

	canvas = init_canvas();
	canvas.map = build_map(read_map(argv[1]));
	count_max(&canvas);
	validate_map(&canvas);

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 160, "so_long");
	canvas.img = mlx_new_image(mlx, 400, 160);
	canvas.addr = mlx_get_data_addr(canvas.img, &canvas.bits_per_pixel, &canvas.line_len, &canvas.endian);
	mlx_put_image_to_window(mlx, win, canvas.img, 0, 0);
	mlx_loop(mlx);
}
