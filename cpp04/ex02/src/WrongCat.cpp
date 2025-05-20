/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:52:51 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/19 18:56:06 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->type = "WrongCat";
    std::cout << "A WrongCat has been created" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "A WrongCat has been created by attribution" << std::endl;
    return (*this);
}

WrongCat::WrongCat(WrongCat const& other)
{
    *this = other;
    std::cout << "A WrongCat has been created by copy" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "A WrongCat has been deleted" << std::endl;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "miau" << std::endl;
}
