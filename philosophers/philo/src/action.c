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

void	take_fork(t_philosopher *philo)
{
	handle_fork(philo, pthread_mutex_lock);
	printf("%ld %d has taken a fork\n", get_cur_time() - philo->start_time, philo->id);
	printf("%ld %d has taken a fork\n", get_cur_time() - philo->start_time, philo->id);
}

void	eat(t_philosopher *philo)
{
	printf("%ld %d is eating\n", get_cur_time() - philo->start_time, philo->id);
	philo->meals++;
	philo->last_meal = get_cur_time();
	usleep(1000 * philo->table->data->time_to_eat);
	handle_fork(philo, pthread_mutex_unlock);
}

void	to_sleep(t_philosopher *philo)
{
	printf("%ld %d is sleeping\n", get_cur_time() - philo->start_time, philo->id);
	usleep(1000 * philo->table->data->time_to_sleep);
}

void	think(t_philosopher *philo)
{
	printf("%ld %d is thinking\n", get_cur_time() - philo->start_time, philo->id);
}

void	die(t_philosopher *philo)
{
	printf("%ld %d died\n", get_cur_time() - philo->start_time, philo->id);
}
