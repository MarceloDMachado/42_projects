/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:36:26 by madias-m          #+#    #+#             */
/*   Updated: 2024/04/07 16:11:31 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int	*get_pid_array(int argc)
{
	int	*pid_array;;

	pid_array = calloc((argc - 2), sizeof(int));
	return (pid_array);
}

int *fork_all(int *pid_array, int argc)
{
	int i;

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

int	func(void)
{
	static int	a;

	return (a++);
}

int	main(int argc, char **argv)
{
	int	*ids;
	int	n;
	int	i;

	if (argc < 5)
		return (printf("invalid arguments count"));
	ids = fork_all(get_pid_array(argc), argc);
	if (!ids)
		n = 1;
	else 
		n = 6;
	if (ids != 0)
		wait(0);
	i = 0;
	printf("%d", func());
	while (i < n + 5)
		printf("%d", i++);
	printf("\n");
	if (ids != 0)
		free(ids);
	return (0);
}
