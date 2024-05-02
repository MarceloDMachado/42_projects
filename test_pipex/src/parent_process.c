/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:32:07 by madias-m          #+#    #+#             */
/*   Updated: 2024/04/28 15:32:09 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	write_out(t_ctrl *data)
{
	int		fd_in;
	int		fd_out;
	char	buffer;

	unlink(data->out);
	fd_in = open(data->in, O_RDONLY);
	fd_out = open(data->out, O_WRONLY | O_CREAT, 0644);
	while (read(fd_in, &buffer, 1))
		write(fd_out, &buffer, 1);
	close(fd_in);
	close(fd_out);
}

void	ft_parent_process(t_ctrl *data, int pid)
{
	int		status;
	int		fd_in;
	char	c;

	close(data->end[1]);
	waitpid(pid, &status, 0);
	unlink(data->in);
	fd_in = open(data->in, O_WRONLY | O_CREAT, 0644);
	while (read(data->end[0], &c, 1))
		write(fd_in, &c, 1);
	close(fd_in);
	if (data->is_last_cmd)
		write_out(data);
	close(data->end[0]);
	free(data->end);
}
