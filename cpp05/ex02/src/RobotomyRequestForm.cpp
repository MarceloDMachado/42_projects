/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:26:06 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/17 16:27:26 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Default Robotomy Form Name", GRADE_TO_SIGN, GRADE_TO_EXECUTE)
{
    this->isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Form", GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(target)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    this->isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm("Robotomy Form", other.GRADE_TO_SIGN, other.GRADE_TO_EXECUTE), target(other.target)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
        this->target = other.target;
    }
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
    std::cout << executor.getName() << " executed Robotomy Form ✅" << std::endl;

    makeDrillingNoises();
    if (std::rand() % 2 == 0)
        std::cout << this->target << " has been robotomized SUCCESSFULLY! 🤖" << std::endl;
    else
        std::cout << this->target << " has not been robotomized!" << std::endl;
}
