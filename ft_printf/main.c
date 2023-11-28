/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:42:18 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/28 20:36:38 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

static int	count_params(char *str)
{
	int		count;
	char	*temp;

	count = 0;
	while (ft_strchr(str, '%'))
	{
		temp = ft_strchr(str, '%');
		if (temp - str > 1)
			count++;
		str = ++temp;
	}
	return (count);
}

void	ft_printf(char *str, ...)
{
	va_list argptr;
	int	count;

	count = count_params(str);
	va_start(argptr, str) ;
	
	printf("%s\n", va_arg(argptr, char *));
	printf("%d\n", va_arg(argptr, int));
	printf("%d\n", va_arg(argptr, int));
	va_end(argptr);
}

int	main(void)
{
	int num;
	char *str;

	num = 65;
	str = "teste!";
	ft_printf("essa eh uma string de teste: %s, %d, %X", str, num, num);
}
