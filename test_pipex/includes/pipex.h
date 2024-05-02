/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:15:09 by madias-m          #+#    #+#             */
/*   Updated: 2024/04/07 18:13:57 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

# define NT 1

typedef struct s_ctrl
{
	char	**cmds;
	char	**envp;
	char	*in;
	char	*out;
	int		*end;
	int		cmd_count;
	int		is_last_cmd;
}	t_ctrl;

int		ft_matrixlen(char **matrix);
void	ft_free_matrix(char ***matrix);
void	ft_parent_process(t_ctrl *data, int pid);
void	ft_child_process(t_ctrl *data, int cmd_index);
int		count_cmds(char **argv);
char	**get_cmds(char **argv);
void	init_ctrl(t_ctrl *data, char **argv, char **envp);
void	ft_exec_cmd(t_ctrl *data, char *cmd);

#endif
