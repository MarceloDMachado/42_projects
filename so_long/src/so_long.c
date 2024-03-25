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
	t_canvas	canvas;

	canvas.img = (void *)0;
	canvas.addr = (void *)0;
	canvas.bpp = 0;
	canvas.line_len = 0;
	canvas.endian = 0;
	canvas.map = (void *)0;
	canvas.max_x = 0;
	canvas.max_y = 0;
	canvas.is_valid = 1;
	return (canvas);
}

void	my_mlx_pixel_put(t_canvas *c, int x, int y, int color)
{
	char	*dst;

	dst = c->addr + (y * c->line_len + x * (c->bpp / 8));
	*(unsigned int *)dst = color;
}

int	invalid_extension(char *path)
{
	if (!ft_strrchr(path, '.') || ft_memcmp(ft_strrchr(path, '.'), ".ber", 4))
		return (1);
	return (0);
}

int	main(int argc, char**argv)
{
	void		*mlx;
	void		*win;
	t_canvas	cvs;

	if (argc != 2)
		return (ft_printf("Error\nInvalid args count!"));
	if (invalid_extension(argv[1]))
		return (ft_printf("Error\nInvalid file extension!"));
	cvs = init_canvas();
	cvs.map = build_map(parse_file_to_list(argv[1]));
	count_max(&cvs);
	if (validate_map(&cvs))
	{
		free_map(&cvs);
		return (1);
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "so_long");
	cvs.img = mlx_new_image(mlx, 1920, 1080);
	cvs.addr = mlx_get_data_addr(cvs.img, &cvs.bpp, &cvs.line_len, &cvs.endian);
	mlx_put_image_to_window(mlx, win, cvs.img, 0, 0);
	mlx_loop(mlx);
}
