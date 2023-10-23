/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:27:08 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/23 15:42:29 by madias-m         ###   ########.fr       */
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
