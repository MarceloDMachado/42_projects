/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:30:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/21 15:44:37 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap potato("Potato");
    ScavTrap avocado("Avocado");
    
    avocado.guardGate();
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