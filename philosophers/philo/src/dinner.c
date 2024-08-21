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

static int	check(t_philosopher *philo)
{
	int	i;

	pthread_mutex_lock(&philo->table->data->rules.mtx);
	i = philo->table->someone_died;
	pthread_mutex_unlock(&philo->table->data->rules.mtx);
	return (i);
}

void	*dinner_prepare(void *p)
{
	int				i;
	t_philosopher	*philo;
	static void		(*f[4])(t_philosopher *) = {take_fork, eat, to_sleep, think};

	philo = (t_philosopher *)p;
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
