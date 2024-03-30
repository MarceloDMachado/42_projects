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
	return (count);
}

void	count_max(t_canvas *canvas)
{
	while (canvas->map[canvas->max_y + 1])
		canvas->max_y++;
	canvas->max_x = ft_strlen(canvas->map[0]) - 1;
	canvas->collectables_count = count_collectables(canvas->map);
}

void	free_map(char ***map)
{
	int	y;

	y = 0;
	while ((*map)[y])
		free((*map)[y++]);
	free(*map);
}

t_coord	get_element_pos(char **map, char element)
{
	t_coord	result;
	int		y;

	y = 1;
	while (map[y])
	{
		if (ft_strchr(map[y], element))
		{
			result.y = y;
			result.x = ft_strchr(map[y], element) - map[y];
			return (result);
		}
		y++;
	}
	result.y = -1;
	result.x = -1;
	return (result);
}

char	**clone_map(t_canvas *cvs)
{
	char	**clone;
	int		y;

	
	clone = ft_calloc(cvs->max_y + 2, sizeof (char *));
	if (!clone)
		return (0);
	y = 0;
	while (y <= cvs->max_y)
	{
		clone[y] = ft_strdup(cvs->map[y]);
		y++;
	}
	return (clone);
}
