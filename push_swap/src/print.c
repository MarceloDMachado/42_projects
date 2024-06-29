/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:23:49 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/17 12:23:50 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print(int **(*stack)(void))
{
	int	len;
	int	i;

	len = stack_len(stack);
	i = 0;
	while (i < len)
		ft_printf("%d\n", *(stack()[i++]));
}

void	test(void)
{
	print(get_stack_a);
	ft_printf("after ra: \n");
	ra();
	print(get_stack_a);
	ft_printf("after rra: \n");
	rra();
	print(get_stack_a);
	ft_printf("after pb (a): \n");
	pb();
	pb();
	print(get_stack_a);
	ft_printf("after pb (b): \n");
	print(get_stack_b);
	ft_printf("after sb: \n");
	sb();
	print(get_stack_b);
}
