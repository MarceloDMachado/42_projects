/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:49:46 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/16 20:59:48 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


static char    *test(void)
 {
     char *c;
     int fd;

     fd = open("teste.txt", O_RDONLY);
     while(read(fd, c, 1) > 0)
     {
         write(1, c, 1);
     }

     write(1, "\n", 1);
     close(fd);
     return (0);
 }

int	main(void)
{
	int	fd;

	//fd = open("teste.txt", O_RDONLY);
	test();
	//close(fd);
	return (0);
}
