/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:53:15 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/19 18:48:23 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << "A Dog has been created" << std::endl;
}

Dog& Dog::operator=(Dog const& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "A Dog has been created by attribution" << std::endl;
    return (*this);
}

Dog::Dog(Dog const& other)
{
    *this = other;
    std::cout << "A Dog has been created by copy" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "A Dog has been deleted" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "au au" << std::endl;
}