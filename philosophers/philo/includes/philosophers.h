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
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philosopher	t_philosopher;
typedef struct s_table			t_table;
typedef struct s_rule			t_rule;
typedef struct s_data			t_data;

struct	s_philosopher {
	int				id;
	int				meals;
	long			last_meal;
	long int		start_time;
	pthread_t		thread;
	t_table			*table;
};

struct	s_table {
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	int				someone_died;
	t_data			*data;
};

struct	s_rule
{
	pthread_mutex_t	mtx;
};

struct	s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_table			table;
	t_rule			rules;
};

int			ft_atoi(const char *nptr);
void		*dinner_prepare(void *data);
void		take_fork(t_philosopher *philo);
void		eat(t_philosopher *philo);
void		to_sleep(t_philosopher *philo);
void		think(t_philosopher *philo);
void		die(t_philosopher *philo);
void		*ft_calloc(size_t nmemb, size_t size);
void		handle_fork(t_philosopher *philo, int (*f)(pthread_mutex_t *));
void		handle_action(t_philosopher *philo, void (*f)(t_philosopher *));
int			check_death(t_data *data);
long int	get_cur_time(void);

#endif
