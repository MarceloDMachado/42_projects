/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:49:24 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/04 14:50:33 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_fill_array(int *arr, int min, int max)
{
	while (min < max)
		*arr++ = min++;
}

int	ft_calc_len(int min, int max)
{	
	int	result;

	result = 0;
	if (min < 0)
		return (min * -1 + max);
	return (max - min);
}

int	*ft_range(int min, int max)
{
	int	*ptr;

	if (min >= max)
		return (NULL);
	ptr = (int *) malloc(ft_calc_len(min, max) * 4);
	if (ptr == NULL)
		return (ptr);
	ft_fill_array(ptr, min, max);
	return (ptr);
}
