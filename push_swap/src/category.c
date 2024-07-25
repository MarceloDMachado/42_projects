/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:56:42 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/24 18:56:43 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_biggest(int *n)
{
	return (*n > *(get_max(stack_b)));
}

int	is_smallest(int *n)
{
	return (*n < *(get_min(stack_b)));
}

int is_middle(int *n)
{
	return (!is_biggest(n) && !is_smallest(n));
}
