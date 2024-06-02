/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:01:08 by madias-m          #+#    #+#             */
/*   Updated: 2024/05/30 11:01:10 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	set(int old, int new)
{
	old = new;
	return (new);
}

int	get(int old, int new)
{
	new = old;
	return (old);
}

int	status(int (*f)(int, int), int new)
{
	static int	status = 1;

	status = f(status, new);
	return (status);
}
