/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:04:13 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/23 15:41:22 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	cast_s1 = (unsigned char *) s1;
	cast_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (cast_s1[i] - cast_s2[i] != 0)
			return (cast_s1[i] - cast_s2[i]);
		i++;
	}
	return (0);
}
