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
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if ((get_cur_time() - data->table.philos[i].last_meal) > data->time_to_die)
		{
			pthread_mutex_lock(&data->rules.mtx);
			data->table.someone_died = 1;
			handle_action(&data->table.philos[i], die);
			pthread_mutex_unlock(&data->rules.mtx);
			return (1);
		}
	}
	return (0);
}
