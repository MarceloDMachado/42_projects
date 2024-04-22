/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:12:21 by madias-m          #+#    #+#             */
/*   Updated: 2024/04/15 17:12:27 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_read(char *path)
{
	int		fd;
	int		fd2;
	int		i;
	char	c;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_printf("invalid path!"));
	i = 0;
	while (i < 5)
	{
		read(fd, &c, 1);
		ft_printf("%c", c);
		i++;
	}
	ft_printf("\n");
	fd2 = 0;
	dup2(fd, fd2);
	close(fd);
	while (i < 10)
	{
		read(fd2, &c, 1);
		ft_printf("%c", c);
		i++;
	}
	return (0);
}
