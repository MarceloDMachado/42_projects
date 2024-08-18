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

typedef struct s_philosopher	t_philosopher;
typedef struct s_table			t_table;
typedef struct s_rule			t_rule;
typedef struct s_data			t_data;

struct	s_philosopher {
	int			id;
	pthread_t	thread;
	t_table		*table;
};

struct	s_table {
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	int				ready_philos;
	t_data			*data;
};

struct	s_rule
{
	pthread_mutex_t	should_start;
	pthread_mutex_t	should_stop;
};

struct	s_data
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	t_table	table;
	t_rule	rules;
};

int		ft_atoi(const char *nptr);
void	*dinner_prepare(void *data);
void	take_fork(int id);
void	eat(int id);
void	sleep(int id);
void	think(int id);
void	die(int id);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
