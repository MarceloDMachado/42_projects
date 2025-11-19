/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:28:45 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/19 13:00:45 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm(void):NAME("DEFAULT_FORM"),GRADE_TO_SIGN(150),GRADE_TO_EXECUTE(150)
{
    this->isSigned = false;
}

AForm::AForm(std::string name):NAME(name),GRADE_TO_SIGN(150),GRADE_TO_EXECUTE(150)
{
    this->isSigned = false;
}

AForm::AForm(std::string name, int gradeToSing, int gradeToExecute):NAME(name), GRADE_TO_SIGN(gradeToSing), GRADE_TO_EXECUTE(gradeToExecute)
{
    this->isSigned = false;
}


AForm::AForm(const AForm& other):NAME(other.NAME),GRADE_TO_SIGN(other.GRADE_TO_SIGN),GRADE_TO_EXECUTE(other.GRADE_TO_EXECUTE)
{
    *this = other;
}

AForm&   AForm::operator=(const AForm& other)
{
    if (this == &other)
        this->isSigned = other.isSigned;
    return (*this);
}

AForm::~AForm(void){}

void    AForm::checkGradeToSign(int n)
{
    if (n > this->GRADE_TO_SIGN)
        throw AForm::GradeTooLowException("Could not sign the form. Grade too low");
}

void    AForm::checkGradeToExecute(int n) const
{
    if (n > this->GRADE_TO_EXECUTE)
        throw AForm::GradeTooLowException("Could not execute the form. Grade too low");
}

void    AForm::beSigned(Bureaucrat bureaucrat)
{
    checkGradeToSign(bureaucrat.getGrade());
    // if (bureaucrat.getGrade() > this->GRADE_TO_SIGN)
	// {
	// 	std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because his grade is too low ❌" << std::endl;
	// 	return ;
	// }
	if (this->isSigned)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because the form is already signed" << std::endl;
		return ;
	}
    this->isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << this->getName() << " ✅"<< std::endl;
}

std::string AForm::getName(void) const
{
    return (this->NAME);
}

bool    AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

int		AForm::getGradeToSign(void) const
{
	return (this->GRADE_TO_SIGN);
}

int		AForm::getGradeToExecute(void) const
{
	return (this->GRADE_TO_EXECUTE);
}

std::ostream&	operator<<(std::ostream& o, AForm const& rhs)
{
	o << "AForm: " << rhs.getName() << ", Grade to sign: " << rhs.getGradeToSign() << ", Grade to execute: " << rhs.getGradeToExecute() << ", is signed: " << rhs.getIsSigned();
	return (o);
}
