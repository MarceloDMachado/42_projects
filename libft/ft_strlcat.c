/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:46:13 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/23 15:02:38 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	int	dest_len;
	int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *) src);
	ft_memcpy(dest + dest_len, src, n - 1);
	dest[n] = 0;
	return (dest_len + src_len);
}
