/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:30:42 by madias-m          #+#    #+#             */
/*   Updated: 2024/09/02 12:30:44 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_table(t_data *data)
{
	data->table.data = data;
	data->table.someone_died = 0;
}

void	alloc_forks(t_data *data)
{
	int	i;

	data->table.forks = ft_calloc((data->nbr_of_philos + 1), sizeof(t_mtx));
	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_mutex_init(data->table.forks + i, NULL);
}

void	alloc_philos(t_data *data)
{
	data->table.philos = ft_calloc((data->nbr_of_philos + 1), sizeof(t_philo));
}

void	prepare_philos(t_data *data, int i)
{
	pthread_mutex_init(&data->table.philos[i].last_meal_mtx, NULL);
	data->table.philos[i].table = &data->table;
	data->table.philos[i].id = i + 1;
	data->table.philos[i].start_time = get_time();
	data->table.philos[i].last_meal = data->table.philos[i].start_time;
}
