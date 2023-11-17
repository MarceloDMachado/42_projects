/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:15:27 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/05 19:18:27 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	main(int argc, char *argv[])
{	
	argv++;
	while (*argv && argc > 0)
	{
		while (*(*argv))
			ft_putchar(*(*argv)++);
		ft_putchar(10);
		argv++;
	}
}
