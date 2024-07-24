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

int find_destiny(int index)
{
	if (is_biggest(get_stack_a()[index]))
		return (index_of(get_stack_b, get_max(get_stack_b)));
	else if (is_smallest(get_stack_a()[index]))
		return (index_of(get_stack_b, get_min(get_stack_b)));
	else
		return (index_of(get_stack_b, get_nearest(index)));
}

void	build_farray(int **(*stack)(void), int index)
{
	append(fmatrix()[index], rotate_func(stack, index));
	replicate(fmatrix()[index], last_func(fmatrix()[index]), calc_distance(stack, stack()[index]));
	append(fmatrix()[index], rotate_func(get_stack_b, find_destiny(index)));
	replicate(fmatrix()[index], last_func(fmatrix()[index]), calc_distance(get_stack_b, get_stack_b()[find_destiny(index)]));
	append(fmatrix()[index], pb);
	reduce(fmatrix()[index]);
}

void	price(void)
{
	int	i;

	i = -1;
	fmatrix();
	while (get_stack_a()[++i])
		build_farray(get_stack_a, i);		
}
