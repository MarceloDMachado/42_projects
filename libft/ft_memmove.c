/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:05:11 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/23 15:42:37 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	if (dest == src)
		return (dest);
	c_dest = (unsigned char *) dest;
	c_src = (unsigned char *) src;
	if (dest > src)
	{
		i = 1;
		while (i <= n)
		{
			c_dest[n - i] = c_src[n - i];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
