/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:05:00 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/31 09:56:47 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = (char *) ft_calloc(len + 1, 1);
	if (start >= len)
		return (substr);
	if (!substr)
		return (0);
	return ((char *) ft_memmove(substr, &s[start], len));
}
