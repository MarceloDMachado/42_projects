/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:49:46 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/21 20:04:08 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	count;
	char	*line;

	fd = open("teste.txt", O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		while (line[count])
		{
			write(1, &(line[count++]), 1);
		}
		count = 0;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
