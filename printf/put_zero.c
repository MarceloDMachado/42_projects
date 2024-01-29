/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:58:55 by madias-m          #+#    #+#             */
/*   Updated: 2024/01/08 19:56:31 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_zero(int len, t_flags *f, int *count)
{
	if (!f->o || (f->hyphen))
		return ;
	while (f->space_fix - len++ > 0)
		put_char(48, 0, count);
}
