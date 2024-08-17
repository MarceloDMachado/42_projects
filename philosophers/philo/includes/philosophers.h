/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:13:17 by madias-m          #+#    #+#             */
/*   Updated: 2024/08/05 17:36:43 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>

typedef struct s_table
{
	pthread_t		*philos;
	pthread_mutex_t	*forks;
}	t_table;

typedef struct s_data
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	t_table	table;
}	t_data;

int		ft_atoi(const char *nptr);
void	*dinner_prepare(void *data);


#endif
