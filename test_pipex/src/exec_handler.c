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

char	*find_path(char **paths, char *program)
{
	char	*correct_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		// pode ser via LS (fork e execve)
		// pode ser via open com concat de strings
		// pode ser via outra forma que desconheço
	}
	return (0);
}

char	*extract_paths(char *path_env)
{
	return (ft_split(path_env, ':'));
}

char	*get_path_env(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	path = 0;
	while (envp[i] && !path)
		path = ft_strnstr(envp[i++], "PATH", 5);
	if (path)
		path = ft_strchr(path, '=') + 1;
	return (path);
}

void	ft_exec_cmd(t_ctrl *data, char *cmd)
{
	char	**sptd_cmd;
	char	*path;

	sptd_cmd = ft_split(cmd, " ");
	path = find_path(extract_paths(get_path_env(data->envp)), sptd_cmd[0]);
	execve(sptd_cmd[0], sptd_cmd, data->envp);
	ft_free_matrix(sptd_cmd);
}
