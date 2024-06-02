/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:50:35 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/03 11:50:36 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_len;

	if (*big == 0 && *little != 0)
		return (0);
	i = 0;
	l_len = (size_t) ft_strlen((char *) little);
	if (l_len == 0)
		return ((char *) big);
	while (i < len && (len - i >= l_len))
		if (ft_memcmp((char *) &big[i++], little, l_len) == 0)
			return ((char *) &big[--i]);
	return (0);
}
