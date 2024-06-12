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

void	sa(void)
{
	int	*temp;

	temp = get_stack_a()[0];
	get_stack_a()[0] = get_stack_a()[1];
	get_stack_a()[1] = temp;
	write(1, "sa\n", 4);
}

void	sb(void)
{
	int	*temp;

	temp = get_stack_b()[0];
	get_stack_b()[0] = get_stack_b()[1];
	get_stack_b()[1] = temp;
	write(1, "sb\n", 4);
}

void	ss(void)
{
	sa();
	sb();
}
