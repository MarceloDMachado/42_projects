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
		data->eat_limit = -1;
	else
		data->eat_limit = ft_atoi(argv[4]);
}

int	check_data(t_data *data)
{
	if (data->nbr_of_philos > 200)
		return (printf("Invalid quantity of Philosophers\n"));
	if (data->time_to_die < 60)
		return (printf("Time to die must be more than 60.\n"));
	if (data->time_to_eat < 60)
		return (printf("Time to eat must be more than 60.\n"));
	if (data->time_to_sleep < 60)
		return (printf("Time to sleep must be more than 60.\n"));
	return (0);
}

void	mount_table(t_data *data)
{
	t_table	*table;
	int		i;

	init_table(data);
	alloc_forks(data);
	alloc_philos(data);
	pthread_mutex_init(&data->rules.death_mtx, NULL);
	pthread_mutex_init(&data->rules.write_mtx, NULL);
	table = &data->table;
	i = -1;
	while (++i < data->nbr_of_philos)
	{
		prepare_philos(data, i);
		pthread_create(&table->philos[i].thread, 0, dinner, &table->philos[i]);
	}
	while (!check_death(data))
		;
}

void	dismount_table(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_join(data->table.philos[i].thread, (void *)0);
	i = -1;
	while (++i < data->nbr_of_philos)
	{
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
