/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:35:37 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/17 19:35:38 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	index_of(int **(*stack)(void), int *n)
{
	int	i;

	i = 0;
	while (stack()[i] != n)
		i++;
	return (i);
}

int	*get_min(int **(*stack)(void))
{
	int	*min;
	int	i;

	i = 0;
	min = stack()[i];
	while (++i < stack_len(stack))
	{
		if (*(stack()[i]) < *min)
			min = stack()[i];
	}
	return (min);
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

int	*get_nearest(int target)
{
	int	*nearest;
	int	i;

	i = 0;
	nearest = get_min(get_stack_b);
	while (get_stack_b()[i])
	{
		if (*get_stack_b()[i] < *get_stack_a()[target])
			if(*get_stack_b()[i] > *nearest)
				nearest = get_stack_b()[i];
		i++;
	}
	return (nearest);
}

int	*last_elem(int **(stack)(void))
{
	return (stack()[stack_len(stack) - 1]);
}
