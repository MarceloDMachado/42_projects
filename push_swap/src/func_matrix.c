/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:08:05 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/22 21:08:06 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	alloc_size(void)
{
	return ((stack_len(get_stack_a) / 2) + (stack_len(get_stack_b) / 2) + 2);
}

t_func	**func_matrix(void)
{
	static t_func	**func_matrix = 0;
	int				i;

	if (func_matrix)
		return (func_matrix);
	i = 0;
	func_matrix = ft_calloc(stack_len(get_stack_a) + 1, sizeof(void *));
	while (i < stack_len(get_stack_a))
		func_matrix[i++] = ft_calloc(alloc_size(), sizeof(void *));
	return (func_matrix);
}

void	append(t_func *f_array, t_func new_func)
{
	while(*f_array)
		f_array++;
	*f_array = new_func;
}

void	free_func_matrix(void)
{
	int	i;

	i = 0;
	while (i < get_argc(0))
		free(func_matrix()[i++]);
	free(func_matrix());
}
