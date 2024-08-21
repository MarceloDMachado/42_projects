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

int	check(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->table->data->rules.death_mtx);
	i = philo->table->someone_died;
	pthread_mutex_unlock(&philo->table->data->rules.death_mtx);
	return (i);
}

void	*dinner(void *p)
{
	static void		(*f[4])(t_philo *) = {take_fork, eat, to_sleep, think};
	int				i;
	t_philo			*philo;

	philo = (t_philo *)p;
	philo->meals = 0;
	i = 0;
	while (!check(philo))
	{
		handle_action(philo, f[i++]);
		if (i == 4)
			i = 0;
	}
	return (NULL);
}
