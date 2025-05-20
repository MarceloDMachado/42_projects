/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:40:01 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/20 15:41:32 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    this->type = "Base AAnimal";
    std::cout << "A base animal has been created" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "A base animal has been created by attribution" << std::endl;
    return (*this);
}

AAnimal::AAnimal(AAnimal const& other)
{
    *this = other;
    std::cout << "A base animal has been created by copy" << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "A base animal has been deleted" << std::endl;
}

void            AAnimal::makeSound(void) const
{
    std::cout << "*Base Animal sound*" << std::endl;
}

std::string     AAnimal::getType(void) const
{
    return (this->type);
}