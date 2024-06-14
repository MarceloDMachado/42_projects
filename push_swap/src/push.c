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
	int	i;

	i = stack_len(get_stack_a);
	while (i > 0)
	{
		get_stack_a()[i] = get_stack_a()[i - 1];
		i--;
	}
	get_stack_a()[i] = get_stack_b()[i];
	while (get_stack_b()[i])
	{
		get_stack_b()[i] = get_stack_b()[i + 1];
		i++;
	}
}

void	pb(void)
{
	int	i;

	i = stack_len(get_stack_b);
	while (i > 0)
	{
		get_stack_b()[i] = get_stack_b()[i - 1];
		i--;
	}
	get_stack_b()[i] = get_stack_a()[i];
	while (get_stack_a()[i])
	{
		get_stack_a()[i] = get_stack_a()[i + 1];
		i++;
	}
}
