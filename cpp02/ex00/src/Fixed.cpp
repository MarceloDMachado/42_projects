/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:16:03 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/12 19:00:03 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void) : rawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->rawValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawValue);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->rawValue = raw;
}