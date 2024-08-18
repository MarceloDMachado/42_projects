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

void	mount_table(t_data *data)
{
	int	i;

	data->table.forks = malloc((data->number_of_philosophers + 1) * sizeof(pthread_mutex_t));
	memset(data->table.forks, 0, (data->number_of_philosophers + 1) * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_init(data->table.forks + i, NULL);
	data->table.philos = malloc((data->number_of_philosophers + 1) * sizeof(t_philosopher));
	memset(data->table.philos, 0, (data->number_of_philosophers + 1) * sizeof(t_philosopher));
	data->table.data = data;
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		data->table.philos[i].id = i + 1;
		pthread_create(&data->table.philos[i].thread, NULL, dinner_prepare, data->table.philos + i);
	}
}

void	dismount_table(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		pthread_join(data->table.philos[i].thread, (void *)0);
		pthread_mutex_destroy(data->table.forks + i);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (1);
	init_data(&data, argc, &argv[1]);
	if (check_data(&data))
		return (1);
	mount_table(&data);
	dismount_table(&data);
	free(data.table.philos);
	free(data.table.forks);
	return (0);
}
