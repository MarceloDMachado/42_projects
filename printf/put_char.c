/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:36:41 by madias-m          #+#    #+#             */
/*   Updated: 2024/01/05 20:45:26 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(int c, void *f, int *count)
{
	before(1, (t_flags *)f, count);
	*count += write(1, &c, 1);
	after(1, (t_flags *)f, count);
}
