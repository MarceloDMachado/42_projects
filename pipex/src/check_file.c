/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:11:49 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/01 11:16:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	file_error(char *file)
{
	ft_putstr_fd("pipex: permission denied: ", 2);
	ft_putendl_fd(file, 2);
}

int	check_infile(char *file, int flag)
{
	int	fd;

	fd = open(file, flag);
	if (fd < 0)
	{
		file_error(file);
		return (status(set, 1));
	}
	close(fd);
	return (status(set, 0));
}

int	check_outfile(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY);
	if (fd < 0 && access(file, F_OK) == 0)
	{
		file_error(file);
		return (status(set, 1));
	}
	if (fd >= 0)
		close(fd);
	return (0);
}
