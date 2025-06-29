/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:01:55 by madias-m          #+#    #+#             */
/*   Updated: 2025/06/11 15:46:07 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
	private:
		std::string const	NAME;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		Bureaucrat&	operator++(void);
		Bureaucrat&	operator--(void);
		Bureaucrat	operator++(int);
		Bureaucrat	operator--(int);
		~Bureaucrat(void);
		std::string	getName(void) const;
		int	getGrade(void) const;
		void	setGrade(int n);
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

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& rhs);

#endif
