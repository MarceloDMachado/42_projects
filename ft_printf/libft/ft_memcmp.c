/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:45:34 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/03 11:50:15 by madias-m         ###   ########.fr       */
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
