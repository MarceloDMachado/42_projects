/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:30:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/18 17:10:30 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap potato("Potato");
    ScavTrap avocado("Avocado");
    
    potato.attack("Avocado");
    avocado.takeDamage(potato.getAttackDamage());
    avocado.beRapaired(5);
    while (potato.getHitPoints() > 0)
    {
        avocado.attack("Potato");
        potato.takeDamage(avocado.getAttackDamage());
    }
    potato.beRapaired(5);
    avocado.attack("Potato");
}