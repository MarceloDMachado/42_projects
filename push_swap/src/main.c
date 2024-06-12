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

void	exit_werror(void)
{
	write(1, "Error\n", 7);
	exit(1);
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
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != 45)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	add(int *set, int n)
{
	static char contains_zero = 0;

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

int	check_duplicates(int n, char **argv)
{
	int	*set;

	set = ft_calloc(n, sizeof(int));
	while (*argv && add(set, ft_atoi(*argv)))
		argv++;
	free(set);
	return (*argv != 0);
}

int	main(int argc, char **argv)
{
	if (argc <= 2 || check_params(&argv[1]))
		exit_werror();
	if (check_duplicates(argc, &argv[1]))
		exit_werror();
	return (0);
}
