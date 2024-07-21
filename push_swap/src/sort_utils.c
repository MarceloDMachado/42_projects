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
	return (*(get_stack_a()[0]) > *(last_elem(get_stack_a)));
}
