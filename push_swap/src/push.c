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
	int	len;
	int	*elem;

	elem = get_stack_b()[0];
	if (!elem)
		return ;
	get_stack_b()[0] = 0;
	fix_stack(get_stack_b);
	len = stack_len(get_stack_a);
	get_stack_a()[len] = elem;
	reverse(get_stack_a);
}

void	pb(void)
{
	int	len;
	int	*elem;

	elem = get_stack_a()[0];
	if (!elem)
		return ;
	get_stack_a()[0] = 0;
	fix_stack(get_stack_a);
	len = stack_len(get_stack_b);
	get_stack_b()[len] = elem;
	reverse(get_stack_b);
}
