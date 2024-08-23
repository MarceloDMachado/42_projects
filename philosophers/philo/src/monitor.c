/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:01:15 by madias-m          #+#    #+#             */
/*   Updated: 2024/08/20 20:01:16 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_death(t_data *data)
{
	int		i;
	long	last_meal;

	i = -1;
	while (++i < data->nbr_of_philos)
	{
		pthread_mutex_lock(&data->table.philos[i].last_meal_mtx);
		last_meal = data->table.philos[i].last_meal;
		if ((get_time() - last_meal) > data->time_to_die)
		{
			pthread_mutex_lock(&data->rules.death_mtx);
			data->table.someone_died = 1;
			handle_action(&data->table.philos[i], die);
			pthread_mutex_unlock(&data->rules.death_mtx);
			pthread_mutex_unlock(&data->table.philos[i].last_meal_mtx);
			return (1);
		}
		pthread_mutex_unlock(&data->table.philos[i].last_meal_mtx);
	}
	return (0);
}
