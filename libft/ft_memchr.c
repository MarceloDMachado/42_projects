/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:45:21 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/03 11:45:23 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast_s;

	cast_s = (unsigned char *) s;
	i = 0;
	while (i < n)
		if (cast_s[i++] == (unsigned char) c)
			return (&cast_s[--i]);
	return (0);
}
