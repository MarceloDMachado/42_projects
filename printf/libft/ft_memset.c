/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:46:23 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/03 11:46:28 by madias-m         ###   ########.fr       */
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
	return (s);
}
