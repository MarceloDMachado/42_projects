/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:30:48 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/09 13:30:49 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	exit_werror(void)
{
    ft_printf("Error\n", 2);
    exit(1);
}

int	check_params(char **argv)
{
	while (*argv)
	{
		while (**argv)
		{
			if (!ft_isdigit(**argv) && **argv != 45)
				return (1);
            (*argv)++;
        }
		argv++;
	}
	return (0);
}

int main(int argc, char **argv)
{
    if (argc <= 2 || check_params(&argv[1]))
        exit_werror();
    return (0);
}