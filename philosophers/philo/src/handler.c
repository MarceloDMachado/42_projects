/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:46:47 by madias-m          #+#    #+#             */
/*   Updated: 2024/08/18 15:46:51 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	handle_fork(t_philo *philo, int (*f)(pthread_mutex_t *))
{
	int	own;
	int	neighbor;

	own = philo->id - 1;
	if (own == philo->table->data->nbr_of_philos)
		neighbor = 0;
	else
		neighbor = own + 1;
	while (f(philo->table->forks + own))
		;
	while (f(philo->table->forks + neighbor))
		;
}

void	handle_action(t_philo *philo, void (*action)(t_philo *))
{
	int	limit;

	limit = philo->table->data->number_of_times_each_philosopher_must_eat;
	if (limit < 0 || philo->meals < limit)
		action(philo);
}
