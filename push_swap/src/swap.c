/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 03:19:54 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/12 03:19:56 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int **(*stack)(void))
{
	if (!stack()[1])
		return ;
	swap_pointer(&(stack()[0]), &(stack()[1]));
}

void	sa(void)
{
	write(1, "sa\n", 3);
	swap(stack_a);
}

void	sb(void)
{
	write(1, "sb\n", 3);
	swap(stack_b);
}

void	ss(void)
{
	write(1, "ss\n", 3);
	swap(stack_a);
	swap(stack_b);
}
