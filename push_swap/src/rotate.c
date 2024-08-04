/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 03:20:27 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/12 03:20:28 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(int **(*stack)(void))
{
	int	len;
	int	i;
	int	j;

	len = size(stack, get, 0);
	i = 0;
	j = 1;
	while (j < len)
		swap_pointer(&(stack()[i++]), &(stack()[j++]));
}

void	ra(void)
{
	write(1, "ra\n", 3);
	rotate(stack_a);
}

void	rb(void)
{
	write(1, "rb\n", 3);
	rotate(stack_b);
}

void	rr(void)
{
	write(1, "rr\n", 3);
	rotate(stack_a);
	rotate(stack_b);
}
