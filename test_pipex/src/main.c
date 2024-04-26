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

int	*get_pid_array(t_ctrl *data)
{
	static int	*pid_array = 0;

	if (!pid_array)	
		pid_array = ft_calloc(data->cmd_count + NT, sizeof(int));
	return (pid_array);
}

void	parent_process(t_ctrl *data, int pid)
{
	int		status;
	char	c;

	close(data->end[1]);
	waitpid(pid, &status, 0);
	while (read(data->end[0], &c, 1))
		write(1, &c, 1);
	close(data->end[0]);
	free(data->end);
}

void	child_process(t_ctrl *data, int	cmd_index)
{
	char *args[] = {"cat", NULL};
	if(cmd_index == 0)
		write(1, "First cmd\n", 11);
	else if (cmd_index < data->cmd_count - 1)
		write(1, "Middle cmd\n", 12);
	else
		write(1, "Last cmd\n", 10);
	close(data->end[0]);
	//execve("/bin/cat", args, data->envp);
	close(data->end[1]);
}

int	count_cmds(char **argv)
{
	int	program;
	int	files;
	
	program = 1;
	files = 2;
	return (ft_matrixlen(argv) - program - files);
}

char	**get_cmds(char **argv)
{
	char	**result;
	int		size;
	int		i;

	size = count_cmds(argv);
	result = ft_calloc(size + NT, sizeof(void *));
	i = 0;
	while (i < size)
	{
		result[i] = ft_strdup(argv[i + 2]);
		i++;
	}
	return (result);
}

int *get_pipe()
{
	int *end;

	end = malloc(2 * sizeof(int));
	dup2(end[1], 1);
	pipe(end);
	return (end);
}

void	build_ctrl(t_ctrl *data, char **argv, char **envp)
{
	data->cmd_count = count_cmds(argv);
	data->envp = envp;
	data->cmds = get_cmds(argv);
	data->in = argv[1];
	data->out = argv[ft_matrixlen(argv) - 1];
}

int	birth_ctrl(t_ctrl *data, int *pid_array)
{
	static int	i = 0;

	data->end = get_pipe();
	pid_array[i] = fork();
	if (pid_array[i] == 0)
	{
		child_process(data, i++);
		free(data->end);
		return (0);
	}
	parent_process(data, pid_array[i]);
	return (i++ < data->cmd_count - 1);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_ctrl	data;

	//if (argc != 5)
	//	return (ft_printf("invalid arguments count"));
	//ids = birth_ctrl(get_pid_array(argv[1], &argc), argc);
	build_ctrl(&data, argv, envp);
	while (birth_ctrl(&data, get_pid_array(&data)))
		i = 0;
	ft_free_matrix(&(data.cmds));
	free(get_pid_array(&data));
	return (0);
}
