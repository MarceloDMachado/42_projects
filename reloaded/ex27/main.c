/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:36:28 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/10 13:45:42 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	while (read(fd, &c, 1))
		write(1, &c, 1);
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else
		ft_display_file(argv[1]);
	return (0);
}
