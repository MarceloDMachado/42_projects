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

void	move(t_farray *farray)
{
	while (*farray)
		(*farray++)();
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

void	sort_five(void)
{
	while (!is_sorted())
	{
		while (size(stack_a, get, 0) > 3)
		{
			while (index_of(stack_a, get_min(stack_a)) != 0)
				rotate_func(stack_a, index_of(stack_a, get_min(stack_a)))();
			pb();
		}
		sort_three();
		while (stack_b()[0])
			pa();
	}
	while (index_of(stack_a, get_min(stack_a)) != 0)
		rotate_func(stack_a, index_of(stack_a, get_min(stack_a)))();
}

void	sort(void)
{
	while (!is_sorted())
	{
		pb();
		pb();
		while (stack_a()[0])
		{
			price();
			move(get_cheapest());
			clean_func_matrix();
		}
		while (index_of(stack_b, get_max(stack_b)) != 0)
			rotate_func(stack_b, index_of(stack_b, get_max(stack_b)))();
		while (stack_b()[0])
			pa();
	}
	while (index_of(stack_a, get_min(stack_a)) != 0)
		rotate_func(stack_a, index_of(stack_a, get_min(stack_a)))();
}

void	(*handle_sort(void))(void)
{
	if (size(stack_a, get, 0) <= 5)
		return (sort_five);
	return (sort);
}
