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

int	*ft_get_pid_arr(t_ctrl *data)
{
	static int	*pid_array = 0;

	if (!pid_array)	
		pid_array = ft_calloc(data->cmd_count + NT, sizeof(int));
	return (pid_array);
}

void	ft_parent_process(t_ctrl *data, int pid)
{
	int		status;
	char	c;
	int		fd_out;

	close(data->end[1]);
	waitpid(pid, &status, 0);
	//fd_out = open(data->out, O_WRONLY);
	//printf("out: %zd", read(data->end[0], &c, 1));
	while (read(data->end[0], &c, 1))
	{
		c -= 32;
		write(1, &c, 1);
	}
	close(data->end[0]);
	free(data->end);
}

void	ft_first_cmd_scope(t_ctrl *data, int cmd_index)
{
	dup2(data->end[1], 1);
	ft_exec_cmd(data, 1);
}

void	middle_cmd_escope(t_ctrl *data, int cmd_index)
{
	dup2(data->end[1], 1);
	dup2(data->in, 0);
	ft_execve(data, 1);
}

void	child_process(t_ctrl *data, int	cmd_index)
{
	char *args[] = {"ls", NULL};
	
	close(data->end[0]);
	if(cmd_index == 0)
		ft_first_cmd_scope(data, cmd_index);
	else if (cmd_index < data->cmd_count - 1)
		ft_middle_cmd_scope(data);
	else
		ft_last_cmd_scope(data);
	//close(data->end[0]);
	//close(1);
	//write(data->end[1], "a", 1);
	//execve("/bin/ls", args, data->envp);
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
	data->fun_cmd_scope = ft_first_cmd_scope;
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
	ft_parent_process(data, pid_array[i]);
	return (i++ < data->cmd_count - 1);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_ctrl	data;

	//if (argc != 5)
	//	return (ft_printf("invalid arguments count"));
	//ids = birth_ctrl(ft_get_pid_arr(argv[1], &argc), argc);
	build_ctrl(&data, argv, envp);
	while (birth_ctrl(&data, ft_get_pid_arr(&data)))
		i = 0;
	ft_free_matrix(&(data.cmds));
	free(ft_get_pid_arr(&data));
	return (0);
}
