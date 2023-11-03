/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:41:59 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/03 11:42:01 by madias-m         ###   ########.fr       */
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
