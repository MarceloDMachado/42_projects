/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:30 by madias-m          #+#    #+#             */
/*   Updated: 2025/10/02 15:06:23 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main() {
    try {
        std::cout << "=== Teste Bureaucrat ===" << std::endl;
        Bureaucrat high("Alice", 1);
        Bureaucrat low("Bob", 150);

        std::cout << high << std::endl;
        std::cout << low << std::endl;

        std::cout << "\n=== Teste ShrubberyCreationForm ===" << std::endl;
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;

        try {
            low.signForm(shrub);
            low.executeForm(shrub);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        high.signForm(shrub);
        high.executeForm(shrub);

        std::cout << "\n=== Teste RobotomyRequestForm ===" << std::endl;
        RobotomyRequestForm robo("Bender");
        std::cout << robo << std::endl;

        try {
            high.executeForm(robo); // tentar executar sem assinar
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        high.signForm(robo);
        for (int i = 0; i < 5; i++) { // testar probabilidade de 50%
            high.executeForm(robo);
        }

        std::cout << "\n=== Teste PresidentialPardonForm ===" << std::endl;
        PresidentialPardonForm pardon("Marvin");
        std::cout << pardon << std::endl;

        try {
            low.signForm(pardon); // sem permissão
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        high.signForm(pardon);
        high.executeForm(pardon);

    } catch (std::exception &e) {
        std::cerr << "Erro geral: " << e.what() << std::endl;
    }

    return 0;
}
