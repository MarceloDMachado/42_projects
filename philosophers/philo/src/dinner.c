/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:10:39 by madias-m          #+#    #+#             */
/*   Updated: 2024/08/17 10:10:54 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	handle_fork(t_philosopher *philo, int (*f)(pthread_mutex_t *))
{
	int own;
	int neighbor;
	
	own = philo->id - 1;
	if (own == philo->table->data->number_of_philosophers)
		neighbor = 0;
	else
		neighbor = own + 1;
	f(philo->table->forks + own);
	f(philo->table->forks + neighbor);
}

void	handle_action(t_philosopher * philo, void (*action)(int))
{
	if (1)
		action(philo->id);
}

void	*dinner_prepare(void *p)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)p;
	handle_fork(philo, pthread_mutex_lock);
	handle_action(philo, take_fork);
	handle_action(philo, eat);
	handle_action(philo, sleep);
	handle_action(philo, think);
	handle_action(philo, die);
	handle_fork(philo, pthread_mutex_unlock);
	return (NULL);
}
