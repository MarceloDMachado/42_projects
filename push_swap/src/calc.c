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

int	calc_distance(int **(*stack)(void), int *n)
{
	if (index_of(stack, n) <= stack_len(stack) / 2)
		return (index_of(stack, n));
	else
		return (stack_len(stack) - index_of(stack, n));
}

void	(*rotate_func(int **(*f)(void), int i)) (void)
{	
	if (i <= stack_len(f) / 2 && f == stack_a)
		return (ra);
	else if (i <= stack_len(f) / 2 && f == stack_b)
		return (rb);
	else if (f == stack_a)
		return (rra);
	else
		return (rrb);
}
