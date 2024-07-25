/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_matrix_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:12:08 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/24 12:12:10 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append(t_farray *farray, t_farray new_func)
{
	while (*farray)
		farray++;
	*farray = new_func;
}

t_farray	last_func(t_farray *farray)
{
	while (*farray)
		farray++;
	return (*(--farray));
}

void	replicate(t_farray *farray, t_farray new_func, unsigned int n)
{
	while (n-- > 1)
		append(farray, new_func);
}

t_farray	*find_f(t_farray *farray, t_farray func)
{
	while (*farray)
	{
		if (*farray == func)
			return (farray);
		farray++;
	}
	return (0);
}

void	dynamic_append(t_farray *farray, t_farray new_func, unsigned int n)
{
	while (n-- > 0)
	{
		if (new_func == rb)
		{
			if (find_f(farray, ra))
				*(find_f(farray, ra)) = rr;
			else
				append(farray, new_func);
		}
		else
		{
			if (find_f(farray, rra))
				*(find_f(farray, rra)) = rrr;
			else
				append(farray, new_func);
		}
	}
}
