/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:17:05 by madias-m          #+#    #+#             */
/*   Updated: 2023/12/08 17:28:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*resolve_line(char **readed)
{
	int		size;
	int		aux;
	char	*line;
	char	*temp;

	if (ft_strchr(*readed, '\n'))
		size = ft_strchr(*readed, '\n') - *readed + 1;
	else
		size = ft_strlen(*readed);
	if (!size)
		return (NULL);
	line = malloc((size + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[size] = 0;
	aux = 0;
	while (aux < size)
	{
		line[aux] = (*readed)[aux];
		aux++;
	}
	temp = ft_strjoin("", &(*readed)[size]);
	free(*readed);
	*readed = temp;
	return (line);
}

void	read_file_aux(char **buff, char **readed, int *r_count, int fd)
{
	char	*temp;

	*r_count = read(fd, *buff, BUFFER_SIZE);
	if (*r_count < 0 || (!*r_count && !ft_strlen(*readed)))
	{
		free(*buff);
		*buff = 0;
		free(*readed);
		*readed = 0;
		return ;
	}
	(*buff)[*r_count] = 0;
	if (!*r_count)
		return ;
	temp = ft_strjoin(*readed, *buff);
	free(*readed);
	*readed = temp;
}

char	*read_file(int fd, char **readed)
{
	char	*buff;
	int		r_count;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	r_count = BUFFER_SIZE;
	while (*readed && r_count == BUFFER_SIZE && !ft_strchr(*readed, 10) && buff)
		read_file_aux(&buff, readed, &r_count, fd);
	if (buff)
		free(buff);
	if (!*readed)
		return (NULL);
	return (resolve_line(readed));
}

char	*get_next_line(int fd)
{
	static char	*readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!readed)
	{
		readed = malloc(sizeof(char));
		if (!readed)
			return (NULL);
		*readed = 0;
	}
	return (read_file(fd, &readed));
}
