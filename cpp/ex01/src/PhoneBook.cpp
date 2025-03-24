/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:37:34 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/24 16:43:49 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.h"

void	PhoneBook::init(void)
{
	this->ContactsCount = 0;
	
	while (run())
		;
	std::cout << "Finalizing...\n";
}

bool	PhoneBook::run(void)
{
	std::cout << "Enter a command: \n";
	std::cin >> this->LastCommand;
	if (!this->LastCommand.compare("EXIT"))
		return (false);
	else if (!this->LastCommand.compare("ADD"))
		this->add_contact();
	else if (!this->LastCommand.compare("SEARCH"))
		this->show_contacts();
	else
		std::cout << "unknow command\n";
	return (true);
}

void	PhoneBook::add_contact(void)
{
	Contact 	new_contact;
	std::string	input;

	std::cout << "Whats your first name?\n";
	std::cin >> input;
	new_contact.set_first_name(input);

	std::cout << "Whats your last name?\n";
	std::cin >> input;
	new_contact.set_last_name(input);

	std::cout << "Whats your nickname?\n";
	std::cin >> input;
	new_contact.set_nickname(input);

	std::cout << "Whats your phone number?\n";
	std::cin >> input;
	new_contact.set_phone_number(input);

	std::cout << "Whats your darkest secret?\n";
	std::cin >> input;
	new_contact.set_darkest_secret(input);
	
	this->Contacts[this->ContactsCount++ % 8] = new_contact;
}

void	PhoneBook::show_contacts(void)
{
	int index;
	
	std::cout << "|index     ";
	std::cout << "|first name";
	std::cout << "|last name ";
	std::cout << "|nickname  |";
	std::cout << std::endl;
	
	index = 0;
	while (index < this->ContactsCount)
	{
		std::cout << "|" << index << "         ";
		this->Contacts[index++].preview();
	}
	
}