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

static void	rotate(int **(*stack)(void))
{
	int	len;
	int	i;
	int	j;

	len = stack_len(stack);
	i = 0;
	j = 1;
	while (j < len)
		swap_pointer(&(stack()[i++]), &(stack()[j++]));
}

void	ra(void)
{
	ft_printf("ra\n");
	rotate(get_stack_a);
}

void	rb(void)
{
	ft_printf("rb\n");
	rotate(get_stack_b);
}

void	rr(void)
{
	ra();
	rb();
}
