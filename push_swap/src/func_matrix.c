/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmatrix.c                                      :+:      :+:    :+:   */
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
	return ((size(stack_a, get, 0) / 2) + (size(stack_b, get, 0) / 2) + 2);
}

t_farray	**fmatrix(void)
{
	static t_farray	**fmatrix = 0;
	int				i;

	if (fmatrix)
		return (fmatrix);
	i = 0;
	fmatrix = ft_calloc(size(stack_a, get, 0) + 1, sizeof(void *));
	while (i < size(stack_a, get, 0))
		fmatrix[i++] = ft_calloc(alloc_size(), sizeof(void *));
	return (fmatrix);
}

void	clean_func_matrix(void)
{
	int	i;
	int	j;

	i = -1;
	while (fmatrix()[++i])
	{
		j = -1;
		while (fmatrix()[i][++j])
			fmatrix()[i][j] = 0;
	}
}

void	free_func_matrix(void)
{
	int	i;

	i = -1;
	while (fmatrix()[++i])
		free(fmatrix()[i]);
	free(fmatrix());
}

int	farray_len(t_farray *f_array)
{
	int	i;

	i = 0;
	while (*f_array)
	{
		f_array++;
		i++;
	}
	return (i);
}
