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

void	parent_process(int **ids, int *end)
{
	int		*init;
	int		status;
	char	c;

	close(end[1]);
	init = *ids;
	while (**ids)
	{
		waitpid(**ids, &status, 0);
		(*ids)++;
	}
	while (read(end[0], &c, 1))
	{
		write(1, &c, 1);
	}
	close(end[0]);
	free(init);
}

void	child_process(char *argv, int *end)
{
	//int	i;

	close(end[0]);
	write(end[1], "child!\n", 8);
	close(end[1]);
	//ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int	*ids;
	int end[2];

	//if (argc < 5)
	//	return (ft_printf("invalid arguments count"));
	pipe(end);
	ids = fork_all(get_pid_array(argv[1], &argc), argc);
	if (ids != 0)
		parent_process(&ids, end);
	else
		child_process(argv[1], end);
	return (0);
}
