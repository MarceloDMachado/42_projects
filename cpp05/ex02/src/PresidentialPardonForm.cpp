/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:29:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/06/17 14:55:32 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):NAME("default"),GRADE_TO_SIGN(25),GRADE_TO_EXECUTE(5)
{
    this->isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name):NAME(name),GRADE_TO_SIGN(25),GRADE_TO_EXECUTE(5)
{
    this->isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):NAME(other.NAME),GRADE_TO_SIGN(25),GRADE_TO_EXECUTE(5)
{
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void){}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	std::cout << "Trying to execute contract";
}


