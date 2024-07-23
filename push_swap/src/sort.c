/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:50:01 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/29 10:50:04 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(void)
{
}

void	sort_three(void)
{
	while (!is_sorted())
	{
		if (*(get_stack_a()[0]) > *(get_stack_a()[1]))
			sa();
		else if (*(get_stack_a()[0]) < *(last_elem(get_stack_a)))
		{
			rra();
			sa();
		}
	}
	while (index_of(get_stack_a, get_min(get_stack_a)) != 0)
		rotate_func(get_stack_a, index_of(get_stack_a, get_min(get_stack_a)))();
}

void	(*handle_sort(void))(void)
{
	if (stack_len(get_stack_a) > 3)
		return (sort);
	return (sort_three);
}
