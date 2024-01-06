/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:48:30 by madias-m          #+#    #+#             */
/*   Updated: 2024/01/05 22:57:05 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*int	main(void)
{
	int num;
	int result;
	int o_result;
	char	*ptr;

	num = -1234;
	ptr = "Sim";
	result = ft_printf("testeM % +d|% 5c|%p|%%|%#X|test", num, *ptr, 0, 0);
	printf("\n");
	o_result = printf("testeO % +d|% 5c|%p|%%|%#X|test", num, *ptr, 0, 0);
	printf("\n");
	printf("my: %d\nor: %d", result, o_result);

}*/

int main(void)
{
	char c;
	char *str;
	int d;
	unsigned int u;
	int my_result;
	int o_result;

	c = 65;
	//str;
	d = 90;
	u = 100;
	
	my_result = ft_printf("My Example:\nchar: %3cstring: %8spointer: %-3pdeci: %-3dunsi: %-3uhexa: %-3XT", c, (void *)0, str, d, u, d);
	ft_printf("\n\n");
	o_result = printf("OO Example:\nchar: %3cstring: %8spointer: %-3pdeci: %-3dunsi: %-3uhexa: %-3XT", c, (void *)0, str, d, u, d);
}
