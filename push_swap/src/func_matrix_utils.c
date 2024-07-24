/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_matrix_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:12:08 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/24 12:12:10 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append(t_func *f_array, t_func new_func)
{
	while (*f_array)
		f_array++;
	*f_array = new_func;
}

void	reply(t_func *f_array, unsigned int n)
{
	if (n <= 1)
		return ;
	while (n-- > 1)
	{
		*(f_array + 1) = *f_array;
		f_array++;
	}
}
