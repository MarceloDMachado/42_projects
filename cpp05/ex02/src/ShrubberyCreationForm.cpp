/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:25:48 by madias-m          #+#    #+#             */
/*   Updated: 2025/06/17 15:05:39 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):NAME("default"),GRADE_TO_SIGN(25),GRADE_TO_EXECUTE(5)
{
    this->isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name):NAME(name),GRADE_TO_SIGN(25),GRADE_TO_EXECUTE(5)
{
    this->isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):NAME(other.NAME),GRADE_TO_SIGN(25),GRADE_TO_EXECUTE(5)
{
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::cout << executor.getName() << " is trying to execute contract";
}

