/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:53:15 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/20 00:31:47 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "A Dog has been created" << std::endl;
}

Dog& Dog::operator=(Dog const& other)
{
    if (this != &other)
    {
        this->type = other.type;
        this->brain = new Brain(*other.brain);
    }
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
    delete this->brain;
    std::cout << "A Dog has been deleted" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "au au" << std::endl;
}