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

void	ft_child_process(t_ctrl *data, int cmd_index)
{
	int	alt_input;

	close(data->end[0]);
	alt_input = open(data->out, O_RDONLY);
	dup2(data->end[1], 1);
	dup2(alt_input, 0);
	ft_exec_cmd(data, data->cmds[cmd_index]);
	close(data->end[1]);
	close(alt_input);
}
