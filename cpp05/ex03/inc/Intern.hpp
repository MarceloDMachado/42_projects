/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:21:49 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/18 18:32:59 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:
		static AForm*         		createShrubberyForm(const std::string& target);
        static AForm*         		createPardonForm(const std::string& target);
        static AForm*         		createRobotomyForm(const std::string& target);
    public:
        Intern(void);
        Intern(const Intern& other);
        ~Intern();
        Intern&						operator=(const Intern& other);
        AForm*						makeForm(const std::string& formName, const std::string& target);
		
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};



#endif
