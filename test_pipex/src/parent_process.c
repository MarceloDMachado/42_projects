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

void	ft_parent_process(t_ctrl *data, int pid)
{
	int		status;
	char	c;
	int		fd_in;
	int		fd_out;

	close(data->end[1]);
	waitpid(pid, &status, 0);
	fd_in = open(data->in, O_RDWR);
	while (read(data->end[0], &c, 1))
		write(fd_in, &c, 1);
	fd_out = open(data->out, O_WRONLY);
	close(data->end[0]);
	free(data->end);
}
