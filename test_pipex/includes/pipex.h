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
	void	*fun_cmd_scope;
}	t_ctrl;

int	ft_read(char *path);
int	my_pipe(void);

#endif
