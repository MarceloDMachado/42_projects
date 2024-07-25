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

void	append(t_farray *f_array, t_farray new_func)
{
	while (*f_array)
		f_array++;
	*f_array = new_func;
}

t_farray	last_func(t_farray *f_array)
{
	while (*f_array)
		f_array++;
	return (*(--f_array));
}

void	replicate(t_farray *f_array, t_farray new_func, unsigned int n)
{
	while (n-- > 1)
		append(f_array, new_func);
}

void	dynamic_append(t_farray *farray, t_farray new_func, unsigned int n)
{
	// do nothing
}
