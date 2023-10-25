/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:13:28 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/20 16:21:01 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	if (!nmemb || !size || nmemb * size > (size_t) - 1)
		return (malloc(1));
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (0);
	return (ft_memset(ptr, 0, nmemb * size));
}
