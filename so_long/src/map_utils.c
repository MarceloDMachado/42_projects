/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:20:43 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/23 15:21:00 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	count_collectables(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'C')
				count++;
		i++;
	}
	ft_printf("count: %d", count);
	return (count);
}

void	count_max(t_canvas *canvas)
{
	while (canvas->map[canvas->max_y + 1])
		canvas->max_y++;
	canvas->max_x = ft_strlen(canvas->map[0]) - 1;
	canvas->collectables_count = count_collectables(canvas->map);
}

void	free_map(t_canvas *canvas)
{
	int	i;

	i = 0;
	while (canvas->map[i])
		free(canvas->map[i++]);
	free(canvas->map);
}
