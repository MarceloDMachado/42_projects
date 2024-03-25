/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:36:18 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/21 19:26:06 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangular(t_canvas *canvas)
{
	int	line_count;
	int	line_size;
	int	i;

	line_count = canvas->max_y;
	line_size = canvas->max_x + 1;
	i = 0;
	while (canvas->map[i])
	{
		ft_printf("%s\n", canvas->map[i]);
		if (line_size != ft_strlen(canvas->map[i++]))
			return (0);
	}
	return (line_size != line_count);
}

int	is_wall_surrounded(t_canvas *c)
{
	int	i;

	i = 0;
	if (!only_wall(c->map[0]) || !only_wall(c->map[c->max_y]))
		return (0);
	i = 1;
	while (i < c->max_y)
	{
		if (c->map[i][0] != 49 || c->map[i][c->max_x] != 49)
			return (0);
		i++;
	}
	return (1);
}

int	constains_necessary_elements(t_canvas *c)
{
	return (check(c, 'P', 1) && check(c, 'E', 1) && check(c, 'C', 0));
}

int	contains_invalid_elements(t_canvas *canvas)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (canvas->map[i])
	{
		while (canvas->map[i][j])
		{
			if (!ft_strchr("01CEP", canvas->map[i][j++]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	validate_map(t_canvas *canvas)
{
	if (!is_rectangular(canvas))
		return (ft_printf("Error\nThe chose map is not rectangular!"));
	if (!is_wall_surrounded(canvas))
		return (ft_printf("Error\nThe chose map is not closed by walls!"));
	if (contains_invalid_elements(canvas))
		return (ft_printf("Error\nThe chose map contains invalid elements!"));
	if (!constains_necessary_elements(canvas))
		return (ft_printf("Error\nThe chose map does not contains all necessary elements to start"));
	return (0);
}
