/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:38:27 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/17 19:38:28 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(void)
{
	int	i;
	int	len;

	i = index_of(stack_a, get_min(stack_a));
	len = size(stack_a, get, 0);
	while (i < len - 1)
	{
		if (*(stack_a()[i]) > *(stack_a()[i + 1]))
			return (0);
		i++;
	}
	if (index_of(stack_a, get_min(stack_a)) == 0)
		return (1);
	i = index_of(stack_a, get_min(stack_a)) - 1;
	while (i > 0)
	{
		if (*(stack_a()[i]) < *(stack_a()[i - 1]))
			return (0);
		i--;
	}
	return (*(stack_a()[0]) > *(last_elem(stack_a)));
}
