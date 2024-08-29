/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:37:28 by madias-m          #+#    #+#             */
/*   Updated: 2024/08/21 16:37:29 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->data->rules.write_mtx);
	printf(str, get_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->data->rules.write_mtx);
}
