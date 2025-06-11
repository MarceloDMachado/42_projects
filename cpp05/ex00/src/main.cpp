/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:30 by madias-m          #+#    #+#             */
/*   Updated: 2025/06/11 14:47:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1;
    Bureaucrat b2("b2");
    Bureaucrat b3("b3", 1);
    try 
    {
        Bureaucrat b4("b4", -151);
        Bureaucrat b5("b5", 151);
    }
	catch (std::exception& e)
	{
		std::cout << "Deu ruim: " << e.what() << std::endl;
	}
}