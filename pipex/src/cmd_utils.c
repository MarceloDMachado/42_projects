/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:35:18 by madias-m          #+#    #+#             */
/*   Updated: 2024/05/29 17:35:21 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **paths, char *program)
{
	int		i;
	char	*half_join;
	char	*full_join;

	if (ft_strchr(program, '/'))
		return (ft_strdup(program));
	i = 0;
	half_join = ft_strjoin("/", program);
	while (paths[i])
	{
		full_join = ft_strjoin(paths[i++], half_join);
		if (access(full_join, F_OK) == 0)
		{
			free(half_join);
			free_matrix(paths);
			return (full_join);
		}
		free(full_join);
	}
	free(half_join);
	free_matrix(paths);
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

char	**get_spltd_cmd(char *cmd)
{
	static char	**spltd_cmd = 0;

	if (spltd_cmd)
		return (spltd_cmd);
	spltd_cmd = ft_split(cmd, ' ');
	return (spltd_cmd);
}

void	run_cmd(char **envp, char *cmd)
{
	char		*path;

	if (!get_spltd_cmd(cmd))
		return ;
	path = find_path(extract(get_path_env(envp)), get_spltd_cmd(cmd)[0]);
	if (!path)
	{
		ft_putstr_fd("./pipex: command not found: ", 2);
		ft_putendl_fd(get_spltd_cmd(cmd)[0], 2);
		free_matrix(get_spltd_cmd(cmd));
		status(set, 127);
		return ;
	}
	execve(path, get_spltd_cmd(cmd), envp);
	status(set, 1);
	free_matrix(get_spltd_cmd(cmd));
	free(path);
}
