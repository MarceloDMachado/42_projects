/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:40:01 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/19 18:54:01 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    this->type = "Base Wrong Animal";
    std::cout << "A base Wrong Animal has been created" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "A base Wrong Animal has been created by attribution" << std::endl;
    return (*this);
}

WrongAnimal::WrongAnimal(WrongAnimal const& other)
{
    *this = other;
    std::cout << "A base Wrong Animal has been created by copy" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "A base Wrong Animal has been deleted" << std::endl;
}

void            WrongAnimal::makeSound(void) const
{
    std::cout << "*Base Wrong Animal sound*" << std::endl;
}

std::string     WrongAnimal::getType(void) const
{
    return (this->type);
}