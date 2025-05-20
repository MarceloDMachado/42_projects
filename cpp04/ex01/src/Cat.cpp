/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:52:51 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/20 15:28:29 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "A Cat has been created" << std::endl;
}

Cat& Cat::operator=(Cat const& other)
{
    if (this != &other)
    {
        this->type = other.type;
        this->brain = new Brain(*other.brain);
    }
    std::cout << "A Cat has been created by attribution" << std::endl;
    return (*this);
}

Cat::Cat(Cat const& other)
{
    *this = other;
    std::cout << "A Cat has been created by copy" << std::endl;
}

Cat::~Cat(void)
{
    delete this->brain;
    std::cout << "A Cat has been deleted" << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << "miau" << std::endl;
}

Brain   Cat::getBrain(void) const
{
    return (*this->brain);
}
