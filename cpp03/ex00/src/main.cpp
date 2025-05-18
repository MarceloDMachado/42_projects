/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:30:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/18 15:21:50 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap potato("Potato");
    ClapTrap avocado("Avocado");
    
    potato.attack("Avocado");
    avocado.takeDamage(potato.getAttackDamage());
    avocado.beRapaired(5);
    while (avocado.getEnergyPoints())
    {
        avocado.attack("Potato");
        potato.takeDamage(avocado.getAttackDamage() + 2);
    }
    potato.beRapaired(5);
    avocado.attack("Potato");
}