/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:23:43 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/22 21:23:45 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void    func(int **(*stack)(void), int *n)
{
    t_func *funcs;

    if (index_of(stack, n) == 0)
        return ;
    funcs = func_matrix()[index_of(stack, n)];
    funcs[0] = rotate_func(stack, index_of(stack, n));
    ft_printf("func: \n");
    funcs[0]();
}

void	price(void)
{
    int	i;

	i = -1;
    func_matrix();
    while (get_stack_a()[++i])
		func(get_stack_a, get_stack_a()[i]);
}