/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:28:45 by madias-m          #+#    #+#             */
/*   Updated: 2025/06/16 15:17:08 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(void):NAME("DEFAULT_FORM"),GRADE_TO_SIGN(150),GRADE_TO_EXECUTE(150)
{
    this->isSigned = false;
}

Form::Form(std::string name):NAME(name),GRADE_TO_SIGN(150),GRADE_TO_EXECUTE(150)
{
    this->isSigned = false;
}

Form::Form(std::string name, int gradeToSign):NAME(name),GRADE_TO_SIGN(gradeToSign),GRADE_TO_EXECUTE(150)
{
    checkGradeToSign(gradeToSign);
    this->isSigned = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute):NAME(name),GRADE_TO_SIGN(gradeToSign),GRADE_TO_EXECUTE(gradeToExecute)
{
    checkGradeToSign(gradeToSign);
    this->isSigned = false;
}

Form::Form(const Form& other):NAME(other.NAME),GRADE_TO_SIGN(other.GRADE_TO_SIGN),GRADE_TO_EXECUTE(other.GRADE_TO_EXECUTE)
{
    *this = other;
}

Form&   Form::operator=(const Form& other)
{
    if (this == &other)
        this->isSigned = other.isSigned;
    return (*this);
}

Form::~Form(void){}

void    Form::checkGradeToSign(int n)
{
    if (n > 150)
        throw Form::GradeTooLowException("Could not create a form. Grade too low");
    if (n < 1)
        throw Form::GradeTooHighException("Could not create a form. Grade too high");
}

void    Form::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() >= this->GRADE_TO_SIGN)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because his grade is too low";
		return ;
	}
	if (this->isSigned)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because the form is already signed";
		return ;
	}
    this->isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << this->getName();
}

std::string Form::getName(void) const
{
    return (this->NAME);
}

bool    Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int		Form::getGradeToSign(void) const
{
	return (this->GRADE_TO_SIGN);
}

int		Form::getGradeToExecute(void) const
{
	return (this->GRADE_TO_EXECUTE);
}

std::ostream&	operator<<(std::ostream& o, Form const& rhs)
{
	o << "Form: " << rhs.getName() << ", Grade to sign: " << rhs.getGradeToSign() << ", Grade to execute: " << rhs.getGradeToExecute() << "is signed: " << rhs.getIsSigned();
	return (o);
}
