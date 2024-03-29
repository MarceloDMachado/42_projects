/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:53:03 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/21 18:51:31 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	invalid_extension(char *path)
{
	if (!ft_strrchr(path, '.') || ft_memcmp(ft_strrchr(path, '.'), ".ber", 4))
		return (1);
	return (0);
}

int	main(int argc, char**argv)
{
	t_canvas	cvs;

	if (argc != 2)
		return (ft_printf("Error\nInvalid args count!"));
	if (invalid_extension(argv[1]))
		return (ft_printf("Error\nInvalid file extension!"));
	cvs.map = build_map(parse_file_to_list(argv[1]));
	count_max(&cvs);
	if (validate_map(&cvs))
	{
		free_map(&(cvs.map));
		return (1);
	}
	start_game(&cvs);
}
