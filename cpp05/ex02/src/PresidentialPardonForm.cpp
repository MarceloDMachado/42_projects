/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:29:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/10/02 15:03:43 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):NAME("default")
{
    this->isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):NAME("PresidentialForm"),target(target)
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

void    PresidentialPardonForm::writePardonNote(void) const
{
    std::cout << this->target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	checkGradeToExecute(executor.getGrade());
    writePardonNote();
}


