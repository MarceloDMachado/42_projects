/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:48:09 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/20 16:02:28 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;

	len = ft_strlen((char *) s);
	ptr = (char *) malloc(++len);
	if (ptr == NULL)
		return (NULL);
	return ((char *) ft_memcpy(ptr, s, len));
}
