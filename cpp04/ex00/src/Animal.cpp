/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:40:01 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/19 18:43:44 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    this->type = "Base Animal";
    std::cout << "A base animal has been created" << std::endl;
}

Animal& Animal::operator=(Animal const& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "A base animal has been created by attribution" << std::endl;
    return (*this);
}

Animal::Animal(Animal const& other)
{
    *this = other;
    std::cout << "A base animal has been created by copy" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "A base animal has been deleted" << std::endl;
}

void            Animal::makeSound(void) const
{
    std::cout << "*Base Animal sound*" << std::endl;
}

std::string     Animal::getType(void) const
{
    return (this->type);
}