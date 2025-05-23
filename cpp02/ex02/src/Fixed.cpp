/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:16:03 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/23 14:45:17 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void) : rawValue(0){}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::Fixed(int const n)
{
	this->rawValue = n << this->fract;
}

Fixed::Fixed(float const n)
{
	this->rawValue = roundf(n * 256);
}

Fixed::~Fixed(void){}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->rawValue = other.getRawBits();
	return *this;
}

Fixed&	Fixed::operator++(void)
{
	this->rawValue++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->rawValue--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	operator++();
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	operator--();
	return (temp);
}

Fixed	Fixed::operator+(Fixed const& other) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(Fixed const& other) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}
fixedC = fixedA * fixedB
Fixed	Fixed::operator*(Fixed const& other) const
{
	Fixed	result;
	result.setRawBits((this->getRawBits() * other.getRawBits()) >> this->fract);
	return (result);
}

Fixed	Fixed::operator/(Fixed const& other) const
{
	Fixed	result;
	result.setRawBits((this->getRawBits() * 256 / other.getRawBits()));
	return (result);
}

bool	Fixed::operator>(Fixed const& other) const {
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(Fixed const& other) const {
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(Fixed const& other) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(Fixed const& other) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(Fixed const& other) const {
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(Fixed const& other) const {
	return (this->getRawBits() != other.getRawBits());
}

int		Fixed::getRawBits(void) const
{
	return (this->rawValue);
}

void	Fixed::setRawBits(const int raw)
{
	this->rawValue = raw;
}

float   Fixed::toFloat(void) const
{
	return (static_cast<float>(this->rawValue) / 256);
}

int     Fixed::toInt(void) const
{
	return (this->rawValue >> this->fract);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed const&	Fixed::min(Fixed const& f1, Fixed const& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed const&	Fixed::max(Fixed const& f1, Fixed const& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

std::ostream&	operator<<(std::ostream& out, Fixed const& fixed)
{
	out << fixed.toFloat();
	return (out);
}
