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

char	*find_path(t_ctrl *data, char *program)
{
	char	*path;
	int		i;

	i = 0;
	path = 0;
	while (data->envp[i] && !path)
		path = ft_strnstr(data->envp[i++], "PATH", 5);
	if (path)
		path = ft_strchr(path, '=') + 1;
	return (path);
}

void	ft_exec_cmd(t_ctrl *data, char *cmd)
{
	char	**splitted;
	char	*path;

	splitted = ft_split(cmd, " ");
	path = find_path(data, splitted[0]);
	execve(splitted[0], splitted, data->envp);
	ft_free_matrix(splitted);
}
