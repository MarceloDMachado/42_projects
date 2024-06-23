/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:58:40 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/12 00:58:41 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	**get_stack_a(void)
{
	static int	**stack_a = 0;
	int			i;

	if (stack_a)
		return (stack_a);
	i = 0;
	stack_a = ft_calloc(get_argc(0), sizeof(void *));
	while (i < get_argc(0) - 1)
		stack_a[i++] = ft_calloc(1, sizeof(int));
	return (stack_a);
}

int	**get_stack_b(void)
{
	static int	**stack_b = 0;

	if (stack_b)
		return (stack_b);
	stack_b = ft_calloc(get_argc(0), sizeof(void *));
	return (stack_b);
}

void	fill_stack(int **(*stack)(void), char **argv)
{
	int	i;

	i = 0;
	while (i < get_argc(0) - 1)
	{
		*(stack()[i]) = ft_atoi(argv[i]);
		i++;
	}
}

void	free_stack(int **(*stack)(void))
{
	int	i;

	i = 0;
	while (i < get_argc(0))
		free(stack()[i++]);
	free(stack());
}

int	stack_len(int **(*stack)(void))
{
	int	i;

	i = 0;
	while (stack()[i])
		i++;
	return (i);
}
