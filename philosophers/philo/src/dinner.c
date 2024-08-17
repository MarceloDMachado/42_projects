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

void *dinner_prepare(void *p)
{
    t_philosopher  *philo;

    philo = (t_philosopher*)p;
    printf("my ID: %d yeah!\n", philo->id);
    return (NULL);
}
