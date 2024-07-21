/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:01:24 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/17 20:01:25 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_distance(int **(*stack)(void), int *n)
{
	if (index_of(stack, n) <= stack_len(stack) / 2)
		return (index_of(stack, n));
	else
		return (stack_len(stack) - index_of(stack, n));
}

int	*calc_price(int *n)
{
	return (n);
}

int	*get_cheapest(int **(*stack)(void))
{
	int	*cheapest;
	int	i;

	i = 0;
	cheapest = stack()[i];
	while (++i < stack_len(stack))
		if (calc_price(stack()[i]) < calc_price(cheapest))
			cheapest = stack()[i];
	return (cheapest);
}
