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

int	*ft_get_pid_arr(t_ctrl *data)
{
	static int	*pid_array = 0;

	if (!pid_array)
		pid_array = ft_calloc(data->cmd_count + NT, sizeof(int));
	return (pid_array);
}

int	*get_pipe(void)
{
	int	*end;

	end = malloc(2 * sizeof(int));
	pipe(end);
	return (end);
}

int	birth_ctrl(t_ctrl *data, int *pid_array)
{
	static int	i = 0;

	data->is_last_cmd = i == data->cmd_count - 1;
	data->end = get_pipe();
	pid_array[i] = fork();
	if (pid_array[i] == 0)
	{
		ft_child_process(data, i++);
		free(data->end);
		return (0);
	}
	ft_parent_process(data, pid_array[i]);
	return (i++ < data->cmd_count - 1);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_ctrl	data;

	if (argc != 5)
		return (ft_printf("invalid arguments count."));
	init_ctrl(&data, argv, envp);
	while (birth_ctrl(&data, ft_get_pid_arr(&data)))
		i = 0;
	
	/*int pid_last;
	int num;
	int ret_code;
	int pid_wait;

	pid_wait = wait(&num);

	while (pid_wait != -1)
	{
		if (pid_wait == pid_last)
			ret_code = (num >> 8) & 0xFF;
		pid_wait = wait(&num);
	}
	*/
	ft_free_matrix(&(data.cmds));
	free(ft_get_pid_arr(&data));
	return (0);
}
