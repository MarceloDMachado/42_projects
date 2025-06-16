/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:30 by madias-m          #+#    #+#             */
/*   Updated: 2025/06/16 16:06:19 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void) {
    std::cout << "===== Welcome to the Bureaucratic Office Simulator! =====" << std::endl;

    // Create bureaucrats with different grades
    std::cout << "\n--- Hiring Bureaucrats ---" << std::endl;
    Bureaucrat intern("Intern", 150);   // Lowest grade
    Bureaucrat manager("Manager", 50);  // Mid-grade
    Bureaucrat director("Director", 1); // Highest grade

    std::cout << intern << std::endl;
    std::cout << manager << std::endl;
    std::cout << director << std::endl;

    // Test grade modifications
    std::cout << "\n--- Promoting/Demoting Bureaucrats ---" << std::endl;
    try {
        std::cout << "Promoting the intern..." << std::endl;
        ++intern;
        std::cout << intern << std::endl;

        std::cout << "Demoting the director..." << std::endl;
        --director;
        std::cout << director << std::endl;

        std::cout << "Attempting to promote the director beyond grade 1..." << std::endl;
        ++director; // Already at grade 1, should throw exception
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    // Create forms with different signing requirements
    std::cout << "\n--- Creating Forms ---" << std::endl;
    Form taxForm("Tax Form", 100);          // Requires grade 100 to sign
    Form contract("Top-Secret Contract", 1); // Requires grade 1 to sign

    std::cout << taxForm << std::endl;
    std::cout << contract << std::endl;

    // Test form signing
    std::cout << "\n--- Attempting to Sign Forms ---" << std::endl;
    intern.signForm(taxForm);      // Intern (grade 149) tries to sign (needs 100)
    manager.signForm(taxForm);     // Manager (grade 50) succeeds
    director.signForm(contract);   // Director (grade 1) succeeds
    director.signForm(contract);   // Director tries to sign again (already signed)

    // Test invalid form creation
    std::cout << "\n--- Testing Invalid Forms ---" << std::endl;
    try {
        Form invalidForm("Invalid Form", 151); // Grade too low
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid Form", 0); // Grade too high
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n===== End of Simulation =====" << std::endl;
    return 0;
}