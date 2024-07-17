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

int	index_of(int **(*stack)(void), int *(*f)(int **(*s)(void)))
{
	int	i;

	i = 0;
	while (stack()[i] != f(stack))
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

int	*last_elem(int **(stack)(void))
{
	return (stack()[stack_len(stack) - 1]);
}
