/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:49:46 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/04 15:42:11 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char *c;

	fd = open("./teste.txt", O_RDONLY);
	read(fd, &c, 1);
	while (*c)
	{
		if(*c != 32)
			write(1, c, 1);
		read(fd, &c, 1);
	}
	return (0);
}
