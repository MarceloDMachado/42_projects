/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:20:06 by madias-m          #+#    #+#             */
/*   Updated: 2024/08/05 17:22:08 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->number_of_philosophers = ft_atoi(argv[0]);
	data->time_to_die = ft_atoi(argv[1]);
	data->time_to_eat = ft_atoi(argv[2]);
	data->time_to_sleep = ft_atoi(argv[3]);
	if (argc < 6)
		return ;
	data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[4]);
}

int	check_data(t_data *data)
{
	if (data->number_of_philosophers > 200)
		return (1);
	if (data->time_to_die < 60)
		return (1);
	if (data->time_to_eat < 60)
		return (1);
	if (data->time_to_sleep < 60)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (1);
	init_data(&data, argc, &argv[1]);
	if (check_data(&data))
		return (1);
	return (0);
}
