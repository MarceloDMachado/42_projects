/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:26:06 by madias-m          #+#    #+#             */
/*   Updated: 2025/10/01 16:40:58 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):NAME("default")
{
    this->isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):NAME("Robotomy Form")
{
    this->isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):NAME(other.NAME)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
        this->target = other.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void){}

void    RobotomyRequestForm::makeDrillingNoises(void) const
{
    std::cout << "* Drilling noises * ";
    std::cout << "Bzzzzzzt! ";
    std::cout << "RRRRRRRRRRRRTT! ";
    std::cout << "TUK-TUK-TUK! ";
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	checkGradeToExecute(executor.getGrade());
    std::cout << executor.getName() << " executed " << this->NAME << std::endl;

    makeDrillingNoises();
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
}
