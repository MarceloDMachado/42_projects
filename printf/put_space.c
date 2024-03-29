/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:26:38 by madias-m          #+#    #+#             */
/*   Updated: 2024/01/13 13:34:19 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_space(int len, t_flags *f, int *count)
{
	while (f->space_fix-- - len > 0)
		put_char(32, 0, count);
}

void	before(int len, t_flags *f, int *count)
{
	if (!f || f->hyphen)
		return ;
	put_space(len, f, count);
}

void	after(int len, t_flags *f, int *count)
{
	if (!f || !f->hyphen)
		return ;
	put_space(len, f, count);
}
