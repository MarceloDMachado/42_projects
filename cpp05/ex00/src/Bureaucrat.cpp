/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:14:37 by madias-m          #+#    #+#             */
/*   Updated: 2025/06/11 14:56:51 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):NAME("Default_Bureaucrat")
{
	setGrade(150);
}

Bureaucrat::Bureaucrat(std::string name):NAME(name)
{
	setGrade(150);
}

Bureaucrat::Bureaucrat(std::string name, int grade):NAME(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):NAME(other.getName())
{
	*this = other;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void){}

std::string	Bureaucrat::getName(void) const
{
	return (this->NAME);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void		Bureaucrat::setGrade(int n)
{
	if (n > 150)
		throw GradeTooHighException("GradeTooHighException");
	if (n < 1)
		throw GradeTooLowException("GradeTooLowException");
	this->grade = n;
}