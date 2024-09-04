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
		print("\033[0;38m%ld %d has taken a fork\n\033[0m", philo);
		print("\033[0;38m%ld %d has taken a fork\n\033[0m", philo);
	}
}

void	eat(t_philo *philo)
{
	philo->meals++;
	pthread_mutex_lock(&philo->last_meal_mtx);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->last_meal_mtx);
	print("\033[1;32m%ld %d is eating\n\033[0m", philo);
	usleep(1000 * philo->table->data->time_to_eat);
	handle_fork(philo, pthread_mutex_unlock);
}

void	to_sleep(t_philo *philo)
{
	if (!check(philo))
		print("\033[0;34m%ld %d is sleeping\n\033[0m", philo);
	usleep(1000 * philo->table->data->time_to_sleep);
}

void	think(t_philo *philo)
{
	print("\033[0;36m%ld %d is thinking\n\033[0m", philo);
}

void	die(t_philo *philo)
{
	print("\033[0;31m%ld %d died\n", philo);
}
