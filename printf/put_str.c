/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:38:39 by madias-m          #+#    #+#             */
/*   Updated: 2024/01/12 19:31:14 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_str_aux(char *str, int *count)
{
	while (*str)
		put_char(*str++, 0, count);
}

void	put_str(char *str, void *f, int *count)
{
	if (!str)
	{
		put_str("(null)", (t_flags *) f, count);
		return ;
	}
	before(ft_strlen(str), (t_flags *) f, count);
	put_str_aux(str, count);
	after(ft_strlen(str), (t_flags *) f, count);
}
