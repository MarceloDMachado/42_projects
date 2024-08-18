/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:25:02 by madias-m          #+#    #+#             */
/*   Updated: 2024/08/18 14:25:03 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_fork(int id)
{
	printf("%d %d has taken a fork\n", 100, id);
}

void	eat(int id)
{
	printf("%d %d is eating\n", 100, id);
}

void	sleep(int id)
{
	printf("%d %d is sleeping\n", 100, id);
}

void	think(int id)
{
	printf("%d %d is thinking\n", 100, id);
}

void	die(int id)
{
	printf("%d %d died\n", 100, id);
}
