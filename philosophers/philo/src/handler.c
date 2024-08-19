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

void	handle_fork(t_philosopher *philo, int (*f)(pthread_mutex_t *))
{
	int	own;
	int	neighbor;

	own = philo->id - 1;
	if (own == philo->table->data->number_of_philosophers)
		neighbor = 0;
	else
		neighbor = own + 1;
	f(philo->table->forks + own);
	f(philo->table->forks + neighbor);
}

void	handle_action(t_philosopher *philo, void (*action)(int))
{
	if (1)
		action(philo->id);
}