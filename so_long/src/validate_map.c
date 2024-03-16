/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:36:18 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/16 18:12:16 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	build_map(char *line)
{
	char *values;
	char **splited;

	splited = ft_split(line, 32);
	while (*splited++)
	{
			
	}
}


int	validate_map(void)
{
	char	**map;
	char	*line;
	int		fd;

	fd = open("../maps/default.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
	}
	return (1);
}
