/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:29:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/10/01 16:15:04 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):NAME("default")
{
    this->isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name):NAME(name)
{
    this->isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):NAME(other.NAME)
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
	std::cout << executor.getName() << " is trying to execute contract";
}


