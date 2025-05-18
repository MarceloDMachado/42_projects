/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:30:26 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/18 15:22:14 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):hit_points(10), energy_points(10), attack_damage(0){}

ClapTrap::ClapTrap(std::string name)
{
	*this = ClapTrap();
	this->name = name;
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
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const& other)
{
	*this = other;
}

ClapTrap::~ClapTrap(void){}

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
