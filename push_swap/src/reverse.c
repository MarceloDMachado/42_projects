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

	len = stack_len(stack);
	while (--len > 0)
		swap_pointer(&(stack()[len]), &(stack()[len - 1]));
}

void	rra(void)
{
	ft_printf("rra\n");
	reverse(get_stack_a);
}

void	rrb(void)
{
	ft_printf("rrb\n");
	reverse(get_stack_b);
}

void	rrr(void)
{
	rra();
	rrb();
}
