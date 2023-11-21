/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:17:05 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/21 20:10:51 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *readed)
{
	char *buff;
	int		read_result;

	buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (0);
	read_result = read(fd, buff, BUFFER_SIZE);
	readed = "";
	while (read_result > 0 && !ft_strchr(buff, '\n'))
	{
		read_result = read(fd, buff, BUFFER_SIZE);
		if (read_result < 0)
			return (0);
		buff[read_result] = 0;
		readed = ft_strjoin(readed, buff);
	}
	free(buff);
	return (readed);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char *readed;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = read_file(fd, readed);
	return (line);
}
