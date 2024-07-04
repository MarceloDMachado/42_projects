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

	len = stack_len(f);
	if (i >= (len / 2))
		return (rra);
	else
		return (ra);
}

int	get_index_of(int **(*stack)(void), int *element)
{
	int	i;

	i = 0;
	while (stack()[i] != element)
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

void	sort(void)
{
	while (get_stack_a()[0])
	{
		while (get_index_of(get_stack_a, get_min(get_stack_a)) != 0)
			get_rotate_func(get_stack_a, get_index_of(get_stack_a, get_min(get_stack_a)))();
		pb();
	}
	while (get_stack_b()[0])
	{
		pa();
	}
}
