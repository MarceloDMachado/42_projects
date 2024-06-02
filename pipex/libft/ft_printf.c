/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:44:21 by madias-m          #+#    #+#             */
/*   Updated: 2024/02/26 18:14:55 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	dynamic_write(va_list arg_lst, char c, t_flags f, int *count)
{
	if (c == 'c')
		put_char(va_arg(arg_lst, int), &f, count);
	else if (c == 's')
		put_str(va_arg(arg_lst, char *), &f, count);
	else if (c == 'p')
		put_ptr(va_arg(arg_lst, size_t), &f, count);
	else if (c == 'd' || c == 'i')
		put_nbr(va_arg(arg_lst, int), &f, count);
	else if (c == 'u')
		put_unbr(va_arg(arg_lst, unsigned int), &f, count);
	else if (c == 'X' || c == 'x')
		put_nbr_hex(va_arg(arg_lst, unsigned int), c - 88, &f, count);
	else if (c == '%')
		put_char(37, 0, count);
}

int	identifies_flag(const char *str, char c)
{
	while (!ft_strchr("cspdiuXx%", *str))
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

void	move_str(const char **str, t_flags *f)
{
	while (ft_strchr("# +-0.", **str))
		(*str)++;
	if (f->space || ft_atoi(*str))
	{
		f->space_fix = ft_atoi(*str);
		if (!f->hyphen && !f->o)
			f->space = 1;
		while (ft_isdigit(**str))
			(*str)++;
	}
}

t_flags	init_flags(const char *str)
{
	t_flags	flags;

	flags.hash = identifies_flag(str, '#');
	flags.plus = identifies_flag(str, '+');
	flags.space = identifies_flag(str, ' ');
	flags.hyphen = identifies_flag(str, '-');
	flags.o = identifies_flag(str, '0');
	flags.space_fix = 0;
	return (flags);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	arg_lst;
	t_flags	flags;

	if (!str)
		return (-1);
	va_start(arg_lst, str);
	count = 0;
	while (*str)
	{
		if (*str == 37)
		{
			str++;
			flags = init_flags(str);
			move_str(&str, &flags);
			dynamic_write(arg_lst, *str, flags, &count);
			str++;
		}
		else
			count += write(1, str++, 1);
	}
	return (count);
}
