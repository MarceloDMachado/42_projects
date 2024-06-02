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

int		check_infile(char *file, int flag);
int		check_outfile(char *file);
int		erase_outfile(char *file);
void	run_cmd(char **envp, char *cmd);
void	free_matrix(char **matrix);
int		status(int (*f)(int, int), int new);
int		get(int old, int new);
int		set(int old, int new);

#endif
