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
	data->nbr_of_philos = ft_atoi(argv[0]);
	data->time_to_die = ft_atoi(argv[1]);
	data->time_to_eat = ft_atoi(argv[2]);
	data->time_to_sleep = ft_atoi(argv[3]);
	if (argc < 6)
		return ;
	data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[4]);
}

int	check_data(t_data *data)
{
	if (data->nbr_of_philos > 200)
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
	int		i;
	t_table	*table;

	table = &data->table;
	table->data = data;
	table->someone_died = 0;
	table->forks = ft_calloc((data->nbr_of_philos + 1), sizeof(t_mtx));
	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_mutex_init(table->forks + i, NULL);
	data->table.philos = ft_calloc((data->nbr_of_philos + 1), sizeof(t_philo));
	i = -1;
	pthread_mutex_init(&data->rules.death_mtx, NULL);
	pthread_mutex_init(&data->rules.write_mtx, NULL);
	while (++i < data->nbr_of_philos)
	{
		data->table.philos[i].table = &data->table;
		data->table.philos[i].id = i + 1;
		data->table.philos[i].start_time = get_time();
		data->table.philos[i].last_meal = table->philos[i].start_time;
		pthread_mutex_init(&data->table.philos[i].last_meal_mtx, NULL);
		pthread_create(&table->philos[i].thread, 0, dinner, table->philos + i);
	}
	while (!check_death(data))
		;
}

void	dismount_table(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_of_philos)
	{
		pthread_join(data->table.philos[i].thread, (void *)0);
		pthread_mutex_destroy(&data->table.philos[i].last_meal_mtx);
		pthread_mutex_destroy(data->table.forks + i);
	}
	pthread_mutex_destroy(&data->rules.death_mtx);
	pthread_mutex_destroy(&data->rules.write_mtx);
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
