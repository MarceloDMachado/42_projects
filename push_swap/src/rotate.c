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

void	ra(void)
{
	int len;
	int	i;
	int	j;

	len = stack_len(get_stack_a);
	i = 0;
	j = 1;
	while (j < len)
		get_stack_a()[i++] = get_stack_a()[j++];
}

void	rb(void)
{
	int len;
	int	i;
	int	j;

	len = stack_len(get_stack_b);
	i = 0;
	j = 1;
	while (j <= len)
		get_stack_b()[i++] = get_stack_b()[j++];
}

void	rr(void)
{
	ra();
	rb();
}