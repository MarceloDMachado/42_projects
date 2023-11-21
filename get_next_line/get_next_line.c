/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:17:05 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/21 18:38:27 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *line)
{
	char *buff;

	buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (0);
	fd++;
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	
	if (BUFFER_SIZE <= 0)
		return (0);
	write(1, "teste", 5);
	line = 0; 
	line = read_file(fd, line);
	return (line);
}
