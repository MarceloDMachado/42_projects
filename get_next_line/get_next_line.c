/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:17:05 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/04 15:04:26 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	c = 0;
	char		prev_c;
	char		p_prev_c;

	prev_c = 0;
	p_prev_c = 0;
	while (read(fd, &c, 1))
	{
		if (p_prev_c != 92 && prev_c == 32)
			return (&c);
		p_prev_c = prev_c;
		prev_c = c;
	}
	return (NULL);
}
