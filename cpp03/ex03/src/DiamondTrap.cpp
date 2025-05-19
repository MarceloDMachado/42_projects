/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 02:04:34 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/19 15:16:04 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):ClapTrap("default_clap_name")
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 30;
	std::cout << "DiamondTrap without a name has been created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name")
{
    this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 30;
	std::cout << "DiamondTrap " << this->name << " has been created" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& other)
{
	if (this != &other)
	{
		this->name = other.getName();
		this->hit_points = other.getHitPoints();
		this->energy_points = other.getEnergyPoints();
		this->attack_damage = other.getAttackDamage();
	}
	std::cout << "DiamondTrap " << this->name << " has been created" << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(DiamondTrap const& other)
{
	*this = other;
	std::cout << "DiamondTrap " << other.getName() << " has been copied";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " is gone..." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Am I " << this->name << " or Am I " << ClapTrap::name << "?"<<std::endl;
}
