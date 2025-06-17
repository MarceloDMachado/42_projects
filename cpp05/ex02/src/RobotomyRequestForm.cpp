/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:26:06 by madias-m          #+#    #+#             */
/*   Updated: 2025/06/17 15:05:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):NAME("default"),GRADE_TO_SIGN(25),GRADE_TO_EXECUTE(5)
{
    this->isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name):NAME(name),GRADE_TO_SIGN(25),GRADE_TO_EXECUTE(5)
{
    this->isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):NAME(other.NAME),GRADE_TO_SIGN(25),GRADE_TO_EXECUTE(5)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void){}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	std::cout << executor.getName() << " is trying to execute contract";
}
