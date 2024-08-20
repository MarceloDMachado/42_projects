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

#include "../includes/philosophers.h"

void	*dinner_prepare(void *p)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)p;
	handle_fork(philo, pthread_mutex_lock);
	handle_action(philo, take_fork);
	handle_action(philo, take_fork);
	handle_action(philo, eat);
	handle_fork(philo, pthread_mutex_unlock);
	handle_action(philo, to_sleep);
	return (NULL);
}
