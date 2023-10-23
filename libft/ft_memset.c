/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:56:18 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/23 15:41:59 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast;

	cast = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		*cast = (unsigned char) c;
		i++;
		cast++;
	}
	return (cast);
}
