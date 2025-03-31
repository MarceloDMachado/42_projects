/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:14:58 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/31 14:38:09 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.h"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	
	(void) name;
	while (--N >= 0)
		horde[N].set_name(name);
	return (horde);
}