/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:17:05 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/23 20:41:57 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*resolve_line(char **readed)
{
	int		size;
	char	*line;

	if (ft_strchr(*readed, '\n'))
		size = ft_strchr(*readed, '\n') - *readed + 1;
	else
		size = ft_strlen(*readed);
	if (!size)
		return (NULL);
	line = malloc((size + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[size--] = 0;
	while (size >= 0)
	{
		line[size] = (*readed)[size];
		size--;
	}
	return (line);
}

char	*read_file(int fd, char **readed)
{
	char	*buff;
	int		r_count;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	r_count = BUFFER_SIZE;
	if (ft_strchr(*readed, '\n'))
		*readed = ft_strchr(*readed, '\n') + 1;
	while (r_count == BUFFER_SIZE && !ft_strchr(*readed, '\n'))
	{
		r_count = read(fd, buff, BUFFER_SIZE);
		if (r_count < 0)
			return (NULL);
		if (r_count)
		{
			buff[r_count] = 0;
			*readed = ft_strjoin(*readed, buff);
		}
	}
	free(buff);
	return (resolve_line(readed));
}

char	*get_next_line(int fd)
{
	static char	*readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!readed)
		readed = "";
	return (read_file(fd, &readed));
}
