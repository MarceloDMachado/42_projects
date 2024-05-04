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
	int		result;
	char	c;

	close(data->end[1]);
	waitpid(pid, &status, 0);
	unlink(data->out);
	result = open(data->out, O_WRONLY | O_CREAT, 0644);
	while (read(data->end[0], &c, 1))
		write(result, &c, 1);
	close(result);
	close(data->end[0]);
	free(data->end);
}
