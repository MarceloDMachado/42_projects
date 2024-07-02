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

void	(*get_rotate_func(int **(*f)(void), int i)) (void)
{
	int		len;
	void	(*func)(void);

	len = stack_len(f);
	if (i >= (len / 2))
	{
		if (f == get_stack_a)
			func = rra;
		else
			func = rrb;
	}
	else
	{
		if (f == get_stack_a)
			func = ra;
		else
			func = rb;
	}
	return (func);
}

int	get_index_of(int **(*stack)(void), int *element)
{
	int	i;

	i = 0;
	while (stack()[i] != element)
		i++;
	return (i);
}

int	*get_max(int **(*stack)(void))
{
	int	*max;
	int	i;

	i = 0;
	max = stack()[i];
	while (++i < stack_len(stack))
	{
		if (*(stack()[i]) > *max)
			max = stack()[i];
	}
	return (max);
}

void	sort(void)
{
	while (get_stack_a()[0])
	{
		while (get_index_of(get_stack_a, get_max(get_stack_a)) != 0)
			get_rotate_func(get_stack_a, get_index_of(get_stack_a, get_max(get_stack_a)))();
		pb();
	}
	while (get_stack_b()[0])
	{
		rrb();
		pa();
	}
}
