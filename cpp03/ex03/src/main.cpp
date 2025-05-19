/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:30:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/19 15:04:10 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap avocado("Avocado");
    DiamondTrap potato("Potato");
    
    std::cout << "======Inital Attributes======" << std::endl;
    std::cout << avocado.getHitPoints() << std::endl;
    std::cout << avocado.getEnergyPoints() << std::endl;
    std::cout << avocado.getAttackDamage() << std::endl;
    
    std::cout << "======Unique Members======" << std::endl;
    avocado.guardGate();
    avocado.highFivesGuys();
    potato.whoAmI();
    
    
    while (potato.getHitPoints() > 0)
    {
        avocado.attack("Potato");
        potato.takeDamage(avocado.getAttackDamage());
    }
    potato.beRapaired(5);
    avocado.whoAmI();
}