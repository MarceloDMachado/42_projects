/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:32:57 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/04 13:47:10 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strcpy(char *src, char *dest)
{
	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		len;

	len = ft_strlen(src);
	ptr = (char *) malloc(++len);
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(src, ptr);
	return (ptr);
}
