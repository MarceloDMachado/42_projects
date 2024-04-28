/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:37:43 by madias-m          #+#    #+#             */
/*   Updated: 2024/04/28 15:37:48 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	count_cmds(char **argv)
{
	int	program;
	int	files;
	
	program = 1;
	files = 2;
	return (ft_matrixlen(argv) - program - files);
}

char	**get_cmds(char **argv)
{
	char	**result;
	int		size;
	int		i;

	size = count_cmds(argv);
	result = ft_calloc(size + NT, sizeof(void *));
	i = 0;
	while (i < size)
	{
		result[i] = ft_strdup(argv[i + 2]);
		i++;
	}
	return (result);
}

void	init_ctrl(t_ctrl *data, char **argv, char **envp)
{
	data->cmd_count = count_cmds(argv);
	data->envp = envp;
	data->cmds = get_cmds(argv);
	data->in = argv[1];
	data->out = argv[ft_matrixlen(argv) - 1];
}
