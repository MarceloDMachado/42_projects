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

void	count_max(t_canvas *canvas)
{
	while (canvas->map[canvas->max_y + 1])
		canvas->max_y++;
	canvas->max_x = ft_strlen(canvas->map[0]) - 1;
}

void	free_map(t_canvas *canvas)
{
	int	i;

	i = 0;
	while (canvas->map[i])
		free(canvas->map[i++]);
	free(canvas->map);
}
