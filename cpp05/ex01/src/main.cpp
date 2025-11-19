/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:30 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/19 12:15:25 by madias-m         ###   ########.fr       */
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

    std::cout << "\n===== End of Simulation =====" << std::endl;
    return 0;
}