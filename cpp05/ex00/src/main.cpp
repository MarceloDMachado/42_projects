/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:30 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/19 12:06:30 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
    Bureaucrat joao("Joao");
    Bureaucrat maria("Maria", 1);

	std::cout << std::endl;
	
	std::cout << "Joao inital grade: " << joao << std::endl;
	std::cout << "Maria inital grade: " << maria << std::endl;

	joao++;
	--maria;

	std::cout << std::endl;

	std::cout << "Joao new grade: " << joao << std::endl;
	std::cout << "Maria new grade: " << maria << std::endl;
	
	std::cout << std::endl;
    try 
    {
        Bureaucrat	gradeTooHigh("tooHigh", -51);
    }
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		Bureaucrat	gradeTooLow("tooLow", 151);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}