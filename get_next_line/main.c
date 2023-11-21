/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:49:46 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/21 18:19:38 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("teste.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
	return (0);
}
