/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:01:24 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/17 20:01:25 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_smaller(int cur, int next)
{
	if (*(stack_a()[cur]) < *(stack_a()[next]))
		return (cur);
	else
		return (next);
}

int	prioritize(int cur, int next)
{
	if (is_biggest(stack_a()[cur]) && is_biggest(stack_a()[next]))
		return (get_smaller(cur, next));
	else if (is_middle(stack_a()[cur]) && is_middle(stack_a()[next]))
		return (get_smaller(cur, next));
	else if (is_smallest(stack_a()[cur]))
		return (next);
	else
		return (cur);
}

t_farray	*get_cheapest(void)
{
	int	cheapest;
	int	i;

	cheapest = 0;
	i = 0;
	while (stack_a()[++i])
	{
		if (farray_len(fmatrix()[i]) < farray_len(fmatrix()[cheapest]))
			cheapest = i;
		else if (farray_len(fmatrix()[i]) == farray_len(fmatrix()[cheapest]))
			cheapest = prioritize(cheapest, i);
	}
	return (fmatrix()[cheapest]);
}

int	calc_distance(int **(*stack)(void), int *n)
{
	if (index_of(stack, n) <= size(stack, get, 0) / 2)
		return (index_of(stack, n));
	else
		return (size(stack, get, 0) - index_of(stack, n));
}

void	(*rotate_func(int **(*f)(void), int i)) (void)
{	
	if (i == 0)
		return (0);
	else if (i <= size(f, get, 0) / 2 && f == stack_a)
		return (ra);
	else if (i <= size(f, get, 0) / 2 && f == stack_b)
		return (rb);
	else if (f == stack_a)
		return (rra);
	else
		return (rrb);
}
