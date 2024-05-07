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
	char	*half_join;
	char	*full_join;
	int		i;

	i = 0;
	half_join = ft_strjoin("/", program);
	if (ft_strchr(program, '/'))
		return (ft_strdup(program));
	while (paths[i])
	{
		full_join = ft_strjoin(paths[i++], half_join);
		if (access(full_join, F_OK) == 0)
		{
			free(half_join);
			return (full_join);
		}
		free(full_join);
	}
	return (0);
}

char	**extract(char *path_env)
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
	{
		if (!ft_memcmp(envp[i], "PATH=", 5))
			path = ft_strchr(envp[i], '=') + 1;
		i++;
	}
	return (path);
}

int	ft_exec_cmd(t_ctrl *data, char *cmd)
{
	char	**sptd_cmd;
	char	*path;

	sptd_cmd = ft_split(cmd, ' ');
	path = find_path(extract(get_path_env(data->envp)), sptd_cmd[0]);
	if (!path)
		return (1);
	execve(path, sptd_cmd, data->envp);
	if (path)
		free(path);
	ft_free_matrix(&sptd_cmd);
	return (0);
}
