/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:25:02 by madias-m          #+#    #+#             */
/*   Updated: 2024/08/18 14:25:03 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_fork(t_philo *philo)
{
	handle_fork(philo, pthread_mutex_lock);
	if (!check(philo))
	{
		print("%ld %d has taken a fork\n", philo);
		print("%ld %d has taken a fork\n", philo);
	}
	else
		handle_fork(philo, pthread_mutex_unlock);
}

void	eat(t_philo *philo)
{
	philo->meals++;
	pthread_mutex_lock(&philo->last_meal_mtx);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->last_meal_mtx);
	print("%ld %d is eating\n", philo);
	usleep(1000 * philo->table->data->time_to_eat);
	handle_fork(philo, pthread_mutex_unlock);
}

void	to_sleep(t_philo *philo)
{
	print("%ld %d is sleeping\n", philo);
	usleep(1000 * philo->table->data->time_to_sleep);
}

void	think(t_philo *philo)
{
	print("%ld %d is thinking\n", philo);
}

void	die(t_philo *philo)
{
	print("%ld %d died\n", philo);
}
