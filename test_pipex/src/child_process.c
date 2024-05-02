/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:35:28 by madias-m          #+#    #+#             */
/*   Updated: 2024/04/28 15:35:29 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_first_cmd_scope(t_ctrl *data, int cmd_index)
{
	dup2(data->end[1], 1);
	ft_exec_cmd(data, data->cmds[cmd_index]);
}

void	ft_middle_cmd_scope(t_ctrl *data, int cmd_index)
{
	dup2(data->end[1], 1);
	dup2(open(data->in, O_RDONLY), 0);
	ft_exec_cmd(data, data->cmds[cmd_index]);
}

void	ft_last_cmd_scope(t_ctrl *data, int cmd_index)
{
	dup2(data->end[1], 1);
	dup2(open(data->in, O_RDONLY), 0);
	ft_exec_cmd(data, data->cmds[cmd_index]);
}

void	child_process(t_ctrl *data, int cmd_index)
{
	close(data->end[0]);
	if (cmd_index == 0)
		ft_first_cmd_scope(data, cmd_index);
	else if (cmd_index < data->cmd_count - 1)
		ft_middle_cmd_scope(data, cmd_index);
	else
		ft_last_cmd_scope(data, cmd_index);
	close(data->end[1]);
}
