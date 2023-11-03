/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:45:52 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/03 11:45:53 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_src = (unsigned char *) src;
	c_dest = (unsigned char *) dest;
	if (c_dest == 0 && c_src == 0 && n > 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
