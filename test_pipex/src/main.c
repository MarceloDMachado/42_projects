/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:36:26 by madias-m          #+#    #+#             */
/*   Updated: 2024/04/07 19:47:54 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

int	ft_matrixlen(char **matrix)
{
	int	size;

	size = 0;
	while (matrix[size])
		size++;
	return (size);
}

void	ft_free_matrix(char ***matrix)
{
	int	y;

	y = 0;
	while ((*matrix)[y])
		free((*matrix)[y++]);
	free(*matrix);
}

int	ft_divide(int dividend, int divisor)
{
	int	i_value;

	i_value = dividend / divisor;
	if ((float)dividend / (float)divisor - i_value > 0.0)
		i_value++;
	return (i_value);
}

int	*get_pid_array(char *str_args, int *size)
{
	int		*pid_array;
	char	**splited;

	splited = ft_split(str_args, ',');
	*size = ft_divide(ft_matrixlen(splited) , 3);
	pid_array = ft_calloc(*size + NT, sizeof(int));
	ft_free_matrix(&splited);
	return (pid_array);
}

int	*fork_all(int *pid_array, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		pid_array[i] = fork();
		if (pid_array[i] == 0)
		{
			free(pid_array);
			return (0);
		}
		i++;
	}
	return (pid_array);
}

void	parent_process(int **ids, char *path)
{
	int	*init;
	int	status;

	init = *ids;
	while (**ids)
	{
		waitpid(**ids, &status, 0);
		(*ids)++;
	}
	free(init);
}

void	child_process(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < 4)
		ft_printf("%d", i++);
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int	*ids;

	//if (argc < 5)
	//	return (ft_printf("invalid arguments count"));
	ids = fork_all(get_pid_array(argv[1], &argc), argc);
	if (ids != 0)
		parent_process(&ids, "./test.txt");
	else
		child_process(argc, argv);
	return (0);
}
