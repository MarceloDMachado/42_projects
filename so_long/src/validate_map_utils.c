/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:32:15 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/23 16:32:18 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check(t_canvas *canvas, char elem, int unique)
{
	int i;
	int	j;
	int	found;

	i = 1;
	j = 0;
	found = 0;
	while (i < canvas->max_y)
	{
		while (canvas->map[i][j])
		{
			if (canvas->map[i][j++] == elem)
				found++;
		}
		j = 0;
		i++;
	}
	if (!found || (unique && found > 1))
		return 0;
	return (1);
}

int only_wall(char *line)
{
	while (*line)
		if (*line++ != 49)
			return (0);
	return (1);
}
