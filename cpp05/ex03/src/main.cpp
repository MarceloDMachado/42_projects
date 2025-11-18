/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:30 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/18 18:38:40 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"

// ANSI color codes
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define GRAY        "\033[90m"

int main() {
    try {
        Intern intern;

    	delete intern.makeForm("shrubbery creation", "InternGarden");
        delete intern.makeForm("presidential pardon", "Jose");
        delete intern.makeForm("robotomy request", "Bender");
        
        intern.makeForm("Weird form", "Weird"); // Should throw exception
    } catch (std::exception &e) {
        std::cerr << RED << BOLD << "[Fatal Error] " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << GREEN << "Program finished successfully." << RESET << std::endl;

    return 0;
}
