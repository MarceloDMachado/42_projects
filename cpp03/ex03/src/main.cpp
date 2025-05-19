/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:30:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/19 15:36:53 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iomanip>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void printHeader(const std::string& title) {
    std::cout << "\n" << MAGENTA << "===== " << title << " =====" << RESET << "\n";
}

int main(void) {
    printHeader("The ClapTrap Chronicles: Battle Begins");
    
    // Character introductions
    std::cout << CYAN << "\nOn the distant planet of ClapTron, four special robots were activated:\n" << RESET;
    
    ClapTrap basic("Basic");
    ScavTrap guard("Sentinel");
    FragTrap happy("Smiley");
    DiamondTrap king("Monarch");
    
    // Initial status display
    printHeader("Initial Status");
    std::cout << YELLOW << basic.getName() << RESET << " (HP: " << basic.getHitPoints() 
              << ", EP: " << basic.getEnergyPoints() << ", AD: " << basic.getAttackDamage() << ")\n";
    std::cout << BLUE << guard.getName() << RESET << " (HP: " << guard.getHitPoints() 
              << ", EP: " << guard.getEnergyPoints() << ", AD: " << guard.getAttackDamage() << ")\n";
    std::cout << GREEN << happy.getName() << RESET << " (HP: " << happy.getHitPoints() 
              << ", EP: " << happy.getEnergyPoints() << ", AD: " << happy.getAttackDamage() << ")\n";
    std::cout << RED << king.getName() << RESET << " (HP: " << king.getHitPoints() 
              << ", EP: " << king.getEnergyPoints() << ", AD: " << king.getAttackDamage() << ")\n";
    
    // Story begins
    printHeader("Chapter 1: The Gatekeeper");
    guard.guardGate();
    std::cout << CYAN << "\nSentinel takes position at ClapTron's main gate.\n" << RESET;
    
    printHeader("Chapter 2: Royal Arrival");
    king.whoAmI();
    std::cout << CYAN << "\nMonarch, the most powerful robot, arrives with his mysterious identity.\n" << RESET;
    
    printHeader("Chapter 3: First Strike");
    basic.attack(guard.getName());
    guard.takeDamage(basic.getAttackDamage());
    std::cout << CYAN << "\nBasic, the simplest robot, attempts to attack Sentinel!\n" << RESET;
    
    printHeader("Chapter 4: Counterattack");
    guard.attack(basic.getName());
    basic.takeDamage(guard.getAttackDamage());
    std::cout << CYAN << "\nSentinel retaliates with full force!\n" << RESET;
    
    printHeader("Chapter 5: Joyful Interruption");
    happy.highFivesGuys();
    std::cout << CYAN << "\nSmiley tries to lighten the mood with a high five, but gets no response...\n" << RESET;
    
    printHeader("Chapter 6: Royal Power");
    king.attack(happy.getName());
    happy.takeDamage(king.getAttackDamage());
    std::cout << CYAN << "\nMonarch demonstrates his power by attacking Smiley!\n" << RESET;
    
    printHeader("Chapter 7: Repair Attempts");
    basic.beRapaired(5);
    happy.beRapaired(10);
    std::cout << CYAN << "\nThe robots attempt repairs during the battle.\n" << RESET;
    
    printHeader("Chapter 8: Final Showdown");
    while (basic.getHitPoints() > 0) {
        king.attack(basic.getName());
        basic.takeDamage(king.getAttackDamage());
    }
    std::cout << CYAN << "\nMonarch repeatedly attacks Basic until destruction!\n" << RESET;
    
    printHeader("Final Status");
    std::cout << YELLOW << basic.getName() << RESET << " (HP: " << basic.getHitPoints() << ")\n";
    std::cout << BLUE << guard.getName() << RESET << " (HP: " << guard.getHitPoints() << ")\n";
    std::cout << GREEN << happy.getName() << RESET << " (HP: " << happy.getHitPoints() << ")\n";
    std::cout << RED << king.getName() << RESET << " (HP: " << king.getHitPoints() << ")\n";
    
    printHeader("Epilogue");
    std::cout << CYAN << "\nWith Basic destroyed, Monarch declares victory and takes control of ClapTron.\n"
              << "Sentinel returns to his gatekeeping duties, while Smiley attempts one last high five...\n"
              << "End of story... for now.\n" << RESET;
    
    return 0;
}