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
	printf("%d %d has taken a fork\n", 100, philo->id);
}

void	eat(t_philosopher *philo)
{
	printf("%d %d is eating\n", 100, philo->id);
	usleep(1000 * philo->table->data->time_to_eat);
}

void	to_sleep(t_philosopher *philo)
{
	printf("%d %d is sleeping\n", 100, philo->id);
	usleep(1000 * philo->table->data->time_to_sleep);
}

void	think(t_philosopher *philo)
{
	printf("%d %d is thinking\n", 100, philo->id);
}

void	die(t_philosopher *philo)
{
	printf("%d %d died\n", 100, philo->id);
}
