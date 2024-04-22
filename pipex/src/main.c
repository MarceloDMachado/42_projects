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
#include <stdlib.h>

int	*get_pid_array(int argc)
{
	int	*pid_array;

	pid_array = ft_calloc((argc - 3) + NT, sizeof(int));
	return (pid_array);
}

int	*fork_all(int *pid_array, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3)
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
	ft_read(path);
	printf("\n");
	free(init);
	ids = 0;
}

void	child_process(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < 10)
		i++;
}

int	main(int argc, char **argv, char **envp)
{
	int	*ids;

	if (argc < 5)
		return (ft_printf("invalid arguments count"));
	ids = fork_all(get_pid_array(argc), argc);
	if (ids != 0)
		parent_process(&ids, "./test.txt");
	else
		child_process(argc, argv);
	return (0);
}
