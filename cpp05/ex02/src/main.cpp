/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:30 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/18 17:20:39 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

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

void	testShrubbery(Bureaucrat& highGrade, Bureaucrat& lowGrade)
{
	std::cout << "\n" << BOLD << CYAN << "=== ShrubberyCreationForm Test ===" << RESET << std::endl;
    ShrubberyCreationForm shrub("garden");
    std::cout << MAGENTA << shrub << RESET << std::endl;

    try {
        lowGrade.signForm(shrub);
        lowGrade.executeForm(shrub);
    } catch (std::exception &e) {
        std::cerr << RED << "[Error] " << e.what() << RESET << std::endl;
    }

    highGrade.signForm(shrub);
    highGrade.executeForm(shrub);
}

void	testRobotomy(Bureaucrat& highGrade, Bureaucrat& lowGrade)
{
	std::cout << "\n" << BOLD << CYAN << "=== RobotomyRequestForm Test ===" << RESET << std::endl;
    RobotomyRequestForm robo("Bender");
    std::cout << MAGENTA << robo << RESET << std::endl;

	try {
	    lowGrade.signForm(robo); // attempt to execute without signing
	} catch (std::exception &e) {
	    std::cerr << RED << "[Error] " << e.what() << RESET << std::endl;
	}

    highGrade.signForm(robo);
    for (int i = 0; i < 5; i++) { // test 50% success rate
        highGrade.executeForm(robo);
    }
}

void	testPardon(Bureaucrat& highGrade, Bureaucrat& lowGrade)
{
	std::cout << "\n" << BOLD << CYAN << "=== PresidentialPardonForm Test ===" << RESET << std::endl;
    PresidentialPardonForm pardon("Marvin");
    std::cout << MAGENTA << pardon << RESET << std::endl;

    try {
        lowGrade.signForm(pardon); // not allowed
    } catch (std::exception &e) {
        std::cerr << RED << "[Error] " << e.what() << RESET << std::endl;
    }

    highGrade.signForm(pardon);
    highGrade.executeForm(pardon);
}


int main() {
    try {
        std::cout << BOLD << BLUE << "=== Bureaucrat Test ===" << RESET << std::endl;
        Bureaucrat high("Alice", 1);
        Bureaucrat low("Bob", 150);

        std::cout << GREEN << high << RESET << std::endl;
        std::cout << GREEN << low << RESET << std::endl;

        testShrubbery(high, low);
		testRobotomy(high, low);
		testPardon(high, low);
    } catch (std::exception &e) {
        std::cerr << RED << BOLD << "[Fatal Error] " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << GREEN << "Program finished successfully." << RESET << std::endl;

    return 0;
}
