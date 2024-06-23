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

#include "../includes/push_swap.h"

int	get_argc(int n)
{
	static int	argc = 0;

	if (!argc)
		argc = n;
	return (argc);
}

int	check_params(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !is_signal(argv[i][j]))
				return (1);
			if (is_signal(argv[i][j]) && j != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	add(int *set, int n)
{
	static char	contains_zero = 0;

	if (contains_zero && n == 0)
		return (0);
	if (n == 0)
	{
		contains_zero = 1;
		return (1);
	}
	while (*set)
	{
		if (*set == n)
			return (0);
		set++;
	}
	*set = n;
	return (1);
}

int	check_dups(char **argv)
{
	int	*set;

	set = ft_calloc(get_argc(0), sizeof(int));
	while (*argv && add(set, ft_atoi(*argv)))
		argv++;
	free(set);
	return (*argv != 0);
}

int	main(int argc, char **argv)
{
	get_argc(argc);
	if (argc <= 2 || check_params(&argv[1]) || check_dups(&argv[1]))
		return (write(1, "Error\n", 7));
	fill_stack(get_stack_a, &argv[1]);
	print(get_stack_a);
	free_stack(get_stack_a);
	free_stack(get_stack_b);
	return (0);
}
