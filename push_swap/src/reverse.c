/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 03:20:43 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/12 03:20:45 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse(int **(*stack)(void))
{
	int	len;

	len = size(stack, get, 0);
	while (--len > 0)
		swap_pointer(&(stack()[len]), &(stack()[len - 1]));
}

void	rra(void)
{
	write(1, "rra\n", 4);
	reverse(stack_a);
}

void	rrb(void)
{
	write(1, "rrb\n", 4);
	reverse(stack_b);
}

void	rrr(void)
{
	write(1, "rrr\n", 4);
	reverse(stack_a);
	reverse(stack_b);
}
