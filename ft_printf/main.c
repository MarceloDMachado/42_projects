/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:42:18 by madias-m          #+#    #+#             */
/*   Updated: 2023/12/02 17:23:13 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

void	dynamic_write(char c, va_list argptr)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(argptr, unsigned int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(argptr, char *), 1);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		ft_put_bigint_base_fd(va_arg(argptr, size_t), "0123456789abcdef", 1);
	}
	else if (c == 'd')
		ft_putnbr_fd(va_arg(argptr, int), 1);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(argptr, int), 1);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(argptr, unsigned int), 1);
	else if (c == 'x')
		ft_putnbr_base_fd(va_arg(argptr, unsigned int), "0123456789abcdef", 1);
	else if (c == 'X')
		ft_putnbr_base_fd(va_arg(argptr, unsigned int), "0123456789ABCDEF", 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

void	ft_printf(const char *str, ...)
{
	va_list argptr;

	va_start(argptr, str);
	while (ft_strchr(str, 37))
	{
		write(1, ft_substr(str, 0, ft_strchr(str, 37) - str), ft_strchr(str, 37) - str);
		dynamic_write(*(ft_strchr(str, 37) + 1), argptr);
		str = ft_strchr(str, 37) + 2;
	}
	write(1, str, ft_strlen(str));
	va_end(argptr);
}

int	main(void)
{
	int num;
	char *str;

	num = 0x65;
	str = "teste!";
	ft_printf("essa eh%dd uma%% string de teste: %s, %d, %X, %p", 10,  str, num, num, &num);
	printf("\n orig: %p", &num);
}
