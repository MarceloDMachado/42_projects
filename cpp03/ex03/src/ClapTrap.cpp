/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:30:26 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/18 17:01:26 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "ClapTrap without a name has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "ClapTrap " << this->name << " has been created" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& other)
{
	if (this != &other)
	{
		this->name = other.getName();
		this->hit_points = other.getHitPoints();
		this->energy_points = other.getEnergyPoints();
		this->attack_damage = other.getAttackDamage();
	}
	std::cout << "ClapTrap " << this->name << " has been created" << std::endl;
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const& other)
{
	*this = other;
	std::cout << "ClapTrap " << other.getName() << " has been copied";
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " is gone..." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points > 0)
	{
		std::cout << this->name << " attacks -> " << target << std::endl;
		this->energy_points--;
	}
	else
		std::cout << this->name << " tried to attack " << target << ", but has not energy for that" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > (int) amount)
	{
		this->hit_points -= amount;
		std::cout << this->name << " received " << amount << " damage." << std::endl;
	}
	else
	{
		this->hit_points = 0;
		std::cout << this->name << " received " << amount << " damage, but it\'s already dead" << std::endl;
	}
}

void	ClapTrap::beRapaired(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << this->name << " tried to repair itself, but it\'s already dead!!! :(" << std::endl;
	}
	else if (this->energy_points > 0)
	{
		std::cout << this->name << " has repaired itself!" << std::endl;
		this->hit_points += amount;
		this->energy_points--;
	}
	else
		std::cout << this->name << " has tried to rapair itself, but has no energy for that" << std::endl;
}

std::string		ClapTrap::getName(void) const
{
	return (this->name);
}

int		ClapTrap::getHitPoints(void) const
{
	return (this->hit_points);
}

int		ClapTrap::getEnergyPoints(void) const
{
	return (this->energy_points);
}

int		ClapTrap::getAttackDamage(void) const
{
	return (this->attack_damage);
}
