/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:41:15 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/21 15:43:19 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap without a name has been created" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << this->name << " has been created" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& other)
{
	if (this != &other)
	{
		this->name = other.getName();
		this->hit_points = other.getHitPoints();
		this->energy_points = other.getEnergyPoints();
		this->attack_damage = other.getAttackDamage();
	}
	std::cout << "FragTrap " << this->name << " has been created" << std::endl;
	return (*this);
}

FragTrap::FragTrap(FragTrap const& other)
{
	*this = other;
	std::cout << "FragTrap " << other.getName() << " has been copied";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " is gone..." << std::endl;
}

void	FragTrap::attack(std::string const& target)
{
	if (this->energy_points > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks -> " << target << std::endl;
		this->energy_points--;
	}
	else
		std::cout << "FragTrap " << this->name << " tried to attack " << target << ", but has not energy for that" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->name << " does request a high-five" << std::endl;
}