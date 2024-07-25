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
	if (is_biggest(stack_a()[index]))
		return (index_of(stack_b, get_max(stack_b)));
	else if (is_smallest(stack_a()[index]))
		return (index_of(stack_b, get_min(stack_b)));
	else
		return (index_of(stack_b, get_nearest(index)));
}

void	print_farray(t_farray *farray)
{
	while (*farray)
	{
		if (*farray == ra)
			write(1, "ra\n", 4);
		else if (*farray == rra)
			write(1, "rra\n", 4);
		else if (*farray == rrr)
			write(1, "rrr\n", 4);
		else if (*farray == rb)
			write(1, "rb\n", 4);
		else if (*farray == rrb)
			write(1, "rrb\n", 4);
		else if (*farray == rr)
			write(1, "rr\n", 4);
		else if (*farray == pb)
			write(1, "pb\n", 4);
		farray++;
	}
}

void	build_farray(int index)
{
	t_farray	*farray;

	farray = fmatrix()[index];
	append(farray, rotate_func(stack_a, index));
	replicate(farray, last_func(farray), calc_distance(stack_a, stack_a()[index]));
	dynamic_append(farray, rotate_func(stack_b, find_destiny(index)), calc_distance(stack_b, stack_b()[find_destiny(index)]));
	append(farray, pb);
	//ft_printf("index: %d | v: %d | f_len: %d | distance: %d\n", index, *(stack_a()[index]), farray_len(farray), calc_distance(stack_a, stack_a()[index]));
	//print_farray(farray);
}

void	price(void)
{
	int	i;

	i = -1;
	fmatrix();
	while (stack_a()[++i])
		build_farray(i);
}
