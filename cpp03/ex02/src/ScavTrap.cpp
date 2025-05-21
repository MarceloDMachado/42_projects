/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:41:15 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/21 15:35:46 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap without a name has been created" << std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << this->name << " has been created" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& other)
{
	if (this != &other)
	{
		this->name = other.getName();
		this->hit_points = other.getHitPoints();
		this->energy_points = other.getEnergyPoints();
		this->attack_damage = other.getAttackDamage();
	}
	std::cout << "ScavTrap " << this->name << " has been created" << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(ScavTrap const& other)
{
	*this = other;
	std::cout << "ScavTrap " << other.getName() << " has been copied";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " is gone..." << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->energy_points > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks -> " << target << std::endl;
		this->energy_points--;
	}
	else
		std::cout << "ScavTrap " << this->name << " tried to attack " << target << ", but has not energy for that" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->name << " is now on Gate keeper mode!" << std::endl;
}