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
	pb();
	pb();
	//while (stack_len(stack_a) > 1)
	//{
		price();
	//	move(get_cheapest());
//		free_func_matrix();
//	}
}

void	sort_three(void)
{
	while (!is_sorted())
	{
		if (*(stack_a()[0]) > *(stack_a()[1]))
			sa();
		else if (*(stack_a()[0]) < *(last_elem(stack_a)))
		{
			rra();
			sa();
		}
	}
	while (index_of(stack_a, get_min(stack_a)) != 0)
		rotate_func(stack_a, index_of(stack_a, get_min(stack_a)))();
}

void	(*handle_sort(void))(void)
{
	if (stack_len(stack_a) > 3)
		return (sort);
	return (sort_three);
}
