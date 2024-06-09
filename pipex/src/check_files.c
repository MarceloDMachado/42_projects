/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:11:49 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/03 07:42:53 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	erase_outfile(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd >= 0)
		close(fd);
	return (1);
}

void	file_error(char *file, int errn)
{	
	if (errn == 0)
		ft_putstr_fd("pipex: permission denied: ", 2);
	else
		ft_putstr_fd("pipex: no such file or directory: ", 2);
	ft_putendl_fd(file, 2);
}

int	check_infile(char *file, int flag)
{
	int	fd;

	fd = open(file, flag);
	if (fd < 0)
	{
		file_error(file, access(file, F_OK));
		return (1);
	}
	close(fd);
	return (0);
}

int	check_outfile(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY);
	if (fd < 0 && access(file, F_OK) == 0)
	{
		file_error(file, 0);
		return (1);
	}
	close(fd);
	return (0);
}

void	check_files(char *infile, char *outfile)
{
	int	in_fail;
	int	out_fail;

	in_fail = check_infile(infile, O_RDONLY);
	out_fail = check_outfile(outfile);
	if (in_fail && !out_fail)
		erase_outfile(outfile);
	else if (out_fail)
		exit(1);
}
