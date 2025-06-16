/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:30 by madias-m          #+#    #+#             */
/*   Updated: 2025/06/11 16:01:57 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b2("b2");
    Bureaucrat b3("b3", 1);

	std::cout << b2++ << std::endl;
	std::cout << --b3 << std::endl;
	
    try 
    {
        Bureaucrat b4("b4", -51);
        Bureaucrat b5("b5", 151);
    }
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "GradeTooLowException: " << e.what() << std::endl;
	}
}