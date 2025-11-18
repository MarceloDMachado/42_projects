/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:25:06 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/18 18:33:56 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern(void){}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern&		Intern::operator=(const Intern& other)
{
	(void) other;
	return (*this);
}

Intern::~Intern(void){}


AForm*		Intern::createShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*		Intern::createPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*		Intern::createRobotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*		Intern::makeForm(const std::string& formName, const std::string& target)
{
	AForm*				(*FormCreator[3])(const std::string&) = {
		createShrubberyForm,
		createPardonForm,
		createRobotomyForm
	};
	const std::string	FormTypes[3] = {
		"shrubbery creation",
    	"presidential pardon",
    	"robotomy request"
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == FormTypes[i])
		{
			AForm *form = FormCreator[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	throw UnknownFormException();
}

const char *Intern::UnknownFormException::what() const throw()
{
	return ("Unknown form type requested");
}