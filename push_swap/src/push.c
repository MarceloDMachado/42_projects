/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 03:20:06 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/12 03:20:07 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(void)
{
	int	len;
	int	*elem;

	write(1, "pa\n", 3);
	elem = stack_b()[0];
	if (!elem)
		return ;
	stack_b()[0] = 0;
	fix_stack(stack_b);
	len = size(stack_a, get, 0);
	stack_a()[len] = elem;
	size(stack_a, set, size(stack_a, get, 0) + 1);
	size(stack_b, set, size(stack_b, get, 0) - 1);
	reverse(stack_a);
}

void	pb(void)
{
	int	len;
	int	*elem;

	write(1, "pb\n", 3);
	elem = stack_a()[0];
	if (!elem)
		return ;
	stack_a()[0] = 0;
	fix_stack(stack_a);
	len = size(stack_b, get, 0);
	stack_b()[len] = elem;
	size(stack_a, set, size(stack_a, get, 0) - 1);
	size(stack_b, set, size(stack_b, get, 0) + 1);
	reverse(stack_b);
}
