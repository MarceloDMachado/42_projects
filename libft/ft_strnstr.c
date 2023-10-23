/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:53:27 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/23 15:05:18 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_len;

	i = 0;
	l_len = (size_t) ft_strlen((char *) little);
	if (l_len == 0)
		return ((char *) big);
	while (i < len && (len - i >= l_len))
		if (ft_memcmp((char *) &big[i++], little, l_len) == 0)
			return ((char *) &big[--i]);
	return (0);
}
