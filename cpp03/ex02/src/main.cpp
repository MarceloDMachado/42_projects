/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:30:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/18 17:23:58 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ScavTrap avocado("Avocado");
    FragTrap potato("Potato");
    
    avocado.guardGate();
    potato.highFivesGuys();
    while (potato.getHitPoints() > 0)
    {
        avocado.attack("Potato");
        potato.takeDamage(avocado.getAttackDamage());
    }
    potato.beRapaired(5);
}