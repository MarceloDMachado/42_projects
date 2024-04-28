/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:17:00 by madias-m          #+#    #+#             */
/*   Updated: 2024/04/28 15:19:13 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exec_cmd(t_ctrl *data, char *cmd)
{
	char	**splitted;

	splitted = ft_split(cmd, " ");
	execve(splitted[0], splitted, data->envp);
	ft_free_matrix(splitted);
}
