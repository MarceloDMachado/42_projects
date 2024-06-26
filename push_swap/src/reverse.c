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

void	rra(void)
{
	int	len;

	len = stack_len(get_stack_a);
	while (--len > 0)
		swap_pointer(&(get_stack_a()[len]), &(get_stack_a()[len - 1]));
}

void	rrb(void)
{
	int	len;

	len = stack_len(get_stack_b);
	while (--len > 0)
		swap_pointer(&(get_stack_b()[len]), &(get_stack_b()[len - 1]));
}

void	rrr(void)
{
	rra();
	rrb();
}
