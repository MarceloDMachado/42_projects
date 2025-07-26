/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:25:48 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/25 22:11:07 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):NAME("default"),GRADE_TO_SIGN(145),GRADE_TO_EXECUTE(137)
{
    this->isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):NAME("ShrubberyCreationForm"),GRADE_TO_SIGN(145),GRADE_TO_EXECUTE(137)
{
    this->target = target;
    this->isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):NAME(other.NAME),GRADE_TO_SIGN(145),GRADE_TO_EXECUTE(137)
{
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        this->target = other.target;    
        this->isSigned = other.isSigned;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::cout << executor.getName() << " is trying to execute contract";
}

void    ShrubberyCreationForm::plantShrubbery(void) const 
{
    std::ofstream file(std::string(target).append("_shrubbery"));

    file << " " << std::endl;
}

