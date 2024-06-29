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
	if (!get_stack_a()[1])
		return ;
	ft_printf("sa\n");
	swap_pointer(&(get_stack_a()[0]), &(get_stack_a()[1]));
}

void	sb(void)
{
	if (!get_stack_b()[1])
		return ;
	ft_printf("sb\n");
	swap_pointer(&(get_stack_b()[0]), &(get_stack_b()[1]));
}

void	ss(void)
{
	sa();
	sb();
}
