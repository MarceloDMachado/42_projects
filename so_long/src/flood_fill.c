/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:01:37 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/29 09:01:38 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	fill(char **map, int y, int x)
{
	if (!ft_strchr("1K", map[y][x]))
	{
		map[y][x] = '1';
		fill(map, y, x + 1);
		fill(map, y, x - 1);
		fill(map, y + 1, x);
		fill(map, y - 1, x);
	}
}

int	check_flood_fill(t_canvas *cvs)
{
	t_coord	p_pos;
	char	**map_clone;
	int		y;
	int		x;

	p_pos = get_element_pos(cvs->map, 'P');
	map_clone = clone_map(cvs);
	fill(map_clone, p_pos.y, p_pos.x);
	y = 0;
	while (map_clone[y])
	{
		ft_printf("%s\n", map_clone[y]);
		x = 0;
		while (map_clone[y][x])
		{
			if (ft_strchr("CEP", map_clone[y][x++]))
			{
				free_map(&map_clone);
				return (0);
			}
		}
		y++;
	}
	free_map(&map_clone);
	return (1);
}
