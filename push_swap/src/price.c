/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:23:43 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/22 21:23:45 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	find_dest(int index)
{
	if (is_biggest(stack_a()[index]))
		return (index_of(stack_b, get_max(stack_b)));
	else if (is_smallest(stack_a()[index]))
		return (index_of(stack_b, get_max(stack_b)));
	else
		return (index_of(stack_b, get_nearest(index)));
}

void	build_farray(int index)
{
	t_farray	*farray;

	farray = fmatrix()[index];
	append(farray, rotate_func(stack_a, index));
	replicate(farray, calc_distance(stack_a, stack_a()[index]));
	dynamic_append(\
		fmatrix()[index], \
		rotate_func(stack_b, find_dest(index)), \
		calc_distance(stack_b, stack_b()[find_dest(index)] \
	));
	append(farray, pb);
}

void	price(void)
{
	int	i;

	i = -1;
	fmatrix();
	while (stack_a()[++i])
		build_farray(i);
}
