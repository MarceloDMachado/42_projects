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

typedef pthread_mutex_t			t_mtx;
typedef struct s_philo			t_philo;
typedef struct s_table			t_table;
typedef struct s_rule			t_rule;
typedef struct s_data			t_data;

struct	s_philo {
	int				id;
	int				meals;
	long			last_meal;
	long int		start_time;
	pthread_mutex_t	last_meal_mtx;
	pthread_t		thread;
	t_table			*table;
};

struct	s_table {
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				someone_died;
	t_data			*data;
};

struct	s_rule
{
	pthread_mutex_t	death_mtx;
	pthread_mutex_t	write_mtx;
};

struct	s_data
{
	int				nbr_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_table			table;
	t_rule			rules;
};

int			ft_atoi(const char *nptr);
void		*dinner(void *data);
void		take_fork(t_philo *philo);
void		eat(t_philo *philo);
void		to_sleep(t_philo *philo);
void		think(t_philo *philo);
void		die(t_philo *philo);
void		*ft_calloc(size_t nmemb, size_t size);
void		handle_fork(t_philo *philo, int (*f)(pthread_mutex_t *));
void		handle_action(t_philo *philo, void (*f)(t_philo *));
int			check_death(t_data *data);
int			check(t_philo *philo);
long int	get_time(void);
void		print(char *str, t_philo *philo);

#endif
