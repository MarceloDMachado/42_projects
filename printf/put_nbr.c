/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:40:12 by madias-m          #+#    #+#             */
/*   Updated: 2024/01/05 22:39:52 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_signal(long *nbr, t_flags *f, int *count)
{
	if (*nbr < 0)
	{
		put_char(45, 0, count);
		*nbr *= -1;
	}
	else if (f->plus)
		put_char(43, 0, count);
	else if (f->space)
		put_char(32, 0, count);
	f->plus = 0;
	f->space = 0;
}

static void	recursive_put(long nbr, int *count)
{
	if (nbr > 9)
	{
		recursive_put(nbr / 10, count);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		put_char(nbr + 48, 0, count);
}

void	put_nbr(long nbr, void *f, int *count)
{
	int	count_bu;

	count_bu = *count;
	put_signal(&nbr, (t_flags *) f, count);
	recursive_put(nbr, count);
	after(*count - count_bu, (t_flags *) f, count);
}
