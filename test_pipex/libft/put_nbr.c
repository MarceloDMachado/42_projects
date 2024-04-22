/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:40:12 by madias-m          #+#    #+#             */
/*   Updated: 2024/02/26 18:16:05 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_signal(long nbr, t_flags *f, int *count)
{
	if (nbr < 0)
		put_char(45, 0, count);
	else if (f->plus)
		put_char(43, 0, count);
	else if (f->space)
		put_char(32, 0, count);
}

static void	recursive_put(long nbr, int *count)
{
	if (nbr > 9)
		recursive_put(nbr / 10, count);
	put_char((nbr % 10) + 48, 0, count);
}

void	put_unbr(unsigned int nbr, t_flags *f, int *count)
{
	f->space = 0;
	put_nbr(nbr, f, count);
}

void	put_nbr(long nbr, t_flags *f, int *count)
{
	int	count_bu;

	count_bu = *count;
	put_signal(nbr, f, count);
	if (nbr < 0)
	{
		nbr *= -1;
		put_zero(ft_count_algarisms(nbr, 10) + 1, f, count);
	}
	else
		put_zero(ft_count_algarisms(nbr, 10) + (f->space || f->plus), f, count);
	recursive_put(nbr, count);
	after(*count - count_bu, f, count);
}
