/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:14:58 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/28 16:45:55 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.h"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie *horde = new Zombie[n];
	
	while (--n >= 0)
		horde[n] = Zombie(name);
	return (horde);
}