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

int	index_of(int **(*stack)(void), int *element)
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

int	is_sorted(void)
{
	int	i;
	int	len;

	i = index_of(get_stack_a, get_min(get_stack_a));
	len = stack_len(get_stack_a);
	while (i < len - 1)
	{
		if (*(get_stack_a()[i]) > *(get_stack_a()[i + 1]))
			return (0);
		i++;
	}
	if (index_of(get_stack_a, get_min(get_stack_a)) == 0)
		return (1);
	i = index_of(get_stack_a, get_min(get_stack_a)) - 1;
	while (i > 0)
	{
		if (*(get_stack_a()[i]) < *(get_stack_a()[i - 1]))
			return (0);
		i--;
	}
	return (*(get_stack_a()[0]) > *(get_stack_a()[stack_len(get_stack_a) - 1]));
}

void	sort(void)
{
	while (!is_sorted())
	{
		if (*(get_stack_a()[0]) > *(get_stack_a()[1]))
			sa();
		else if (*(get_stack_a()[0]) < *(get_stack_a()[stack_len(get_stack_a) - 1]))
		{
			rra();
			sa();
			if (get_argc(0) > 3)
				ra();
		}
		else
		{
			while (index_of(get_stack_a, get_max(get_stack_a)) != 0)
				get_rotate_func(get_stack_a, index_of(get_stack_a, get_max(get_stack_a)))();
		}
	}
	while (index_of(get_stack_a, get_min(get_stack_a)) != 0)
		get_rotate_func(get_stack_a, index_of(get_stack_a, get_min(get_stack_a)))();
}
