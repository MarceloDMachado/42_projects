/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:28:35 by madias-m          #+#    #+#             */
/*   Updated: 2025/06/16 15:52:33 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	NAME;
		bool				isSigned;
		int const			GRADE_TO_SIGN;
		int const			GRADE_TO_EXECUTE;
		void				checkGradeToSign(int n);
	public:
		Form(void);
		Form(std::string name);
		Form(std::string name, int gradeToSign);
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);
		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		beSigned(Bureaucrat bureaucrat);
		class GradeTooHighException : public std::exception
		{
    		private:
    		    std::string message;
    		public:
    		    GradeTooHighException(std::string msg):message(msg){};
    		    ~GradeTooHighException(void) throw() {};
    		    const char* what() const throw() {return (this->message.c_str());};
		};
		class GradeTooLowException : public std::exception
		{
    		private:
    		    std::string message;
    		public:
    		    GradeTooLowException(std::string msg):message(msg){};
    		    ~GradeTooLowException(void) throw() {};
    		    const char* what() const throw() {return (this->message.c_str());};
		};
};

std::ostream&	operator<<(std::ostream& o, Form const& rhs);

#endif
