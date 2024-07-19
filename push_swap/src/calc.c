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

int	calc_price(int *n)
{
	
}

int	*get_cheapest(int **(*stack)(void))
{
	int	*cheapest;
	int	i;

	i = 0;
	cheapest = stack()[i];
	while (++i < stack_len(stack))
		if (calc_price(stack()[i]) < calc_price(cheapest))
			cheapest = calc_price(stack()[i]);
	return (cheapest);
}
