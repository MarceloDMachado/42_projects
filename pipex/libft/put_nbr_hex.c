/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:41:30 by madias-m          #+#    #+#             */
/*   Updated: 2024/02/26 18:18:45 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_ptr(size_t n, t_flags *f, int *count)
{
	f->hash = 1;
	if (!n)
		put_str("(nil)", 0, count);
	else
		put_nbr_hex(n, 1, f, count);
}

static void	recursive_put(size_t n, int is_low, int *count)
{
	if (n > 15)
	{
		recursive_put(n / 16, is_low, count);
		n = n % 16;
	}
	if (n > 9)
		put_char((n % 10) + 65 + is_low, 0, count);
	else
		put_char(n + 48, 0, count);
}

void	put_nbr_hex(size_t n, int is_low, t_flags *f, int *count)
{
	int	count_bu;

	count_bu = *count;
	if (is_low)
		is_low = 32;
	if (f->hash && n > 0)
	{
		if (is_low)
			put_str("0x", 0, count);
		else
			put_str("0X", 0, count);
		put_zero(ft_count_algarisms(n, 16) + 2, f, count);
	}
	else
		put_zero(ft_count_algarisms(n, 16), f, count);
	recursive_put(n, is_low, count);
	after(*count - count_bu, f, count);
}
