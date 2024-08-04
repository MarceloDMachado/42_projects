/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:36:09 by madias-m          #+#    #+#             */
/*   Updated: 2024/08/02 16:36:11 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	set(int *old, int new)
{
	*old = new;
	return (new);
}

int	get(int *old, int new)
{
	new = *old;
	return (new);
}

int	size(int **(*stack)(void), int (*f)(int *, int), int n)
{
	static int	a_size = 0;
	static int	b_size = 0;

	if (stack == stack_a)
		return (f(&a_size, n));
	else
		return (f(&b_size, n));
}

void	print_cur_sizes(void)
{
	ft_printf("a: %d\n", size(stack_a, get, 0));
	ft_printf("b: %d\n", size(stack_b, get, 0));
	ft_printf("al: %d\n", stack_len(stack_a));
	ft_printf("bl: %d\n", stack_len(stack_b));
}
