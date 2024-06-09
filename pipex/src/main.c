/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:13:30 by madias-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:13:31 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	*get_pipe(void)
{
	static int	*end = 0;

	if (end)
		return (end);
	end = malloc(2 * sizeof(int));
	pipe(end);
	return (end);
}

void	parent(char **argv, char **envp)
{
	int		fd;

	close(get_pipe()[1]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putendl_fd(argv[4], 2);
		status(set, 1);
	}
	else
	{
		dup2(get_pipe()[0], 0);
		dup2(fd, 1);
		run_cmd(envp, argv[3]);
		close(fd);
		close(get_pipe()[0]);
	}
}

void	child(char **argv, char **envp)
{
	int	fd;

	close(get_pipe()[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd >= 0)
	{
		dup2(get_pipe()[1], 1);
		dup2(fd, 0);
		run_cmd(envp, argv[2]);
		close(fd);
	}
	close(get_pipe()[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int		pid;

	if (argc != 5)
		return (1);
	check_files(argv[1], argv[4]);
	get_pipe();
	pid = fork();
	if (pid == 0)
		child(argv, envp);
	else
		parent(argv, envp);
	free(get_pipe());
	return (status(get, 0));
}
