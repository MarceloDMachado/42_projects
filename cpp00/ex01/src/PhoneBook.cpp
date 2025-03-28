/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:37:34 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/27 13:26:24 by madias-m         ###   ########.fr       */
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
	std::cout << "Enter a command (ADD, SEARCH or EXIT): " << std::endl;
	std::getline(std::cin, this->LastCommand);
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

void	receive_data_input(const char *msg, Contact *contact, set set_method)
{
	std::string input;
	
	do {
		std::cout << msg;
		std::getline(std::cin, input);
	} while (input.empty());
	(contact->*set_method)(input);
}

void	PhoneBook::add_contact(void)
{
	Contact 	new_contact;
	std::string	input;

	receive_data_input("Whats your first name?\n", &new_contact, &Contact::set_first_name);
	receive_data_input("Whats your last name?\n", &new_contact, &Contact::set_last_name);
	receive_data_input("Whats your nickname?\n", &new_contact, &Contact::set_nickname);
	receive_data_input("Whats your phone number?\n", &new_contact, &Contact::set_phone_number);
	receive_data_input("Whats your darkest secret?\n", &new_contact, &Contact::set_darkest_secret);
	
	this->Contacts[this->ContactsCount++ % 8] = new_contact;
	if (this->ContactsCount > 8)
		this->ContactsCount = 8;
}


static	void	show_header(void)
{
	std::cout << "|INDEX     ";
	std::cout << "|FIRST NAME";
	std::cout << "|LAST NAME ";
	std::cout << "|NICKNAME  |";
	std::cout << std::endl;	
}

void	PhoneBook::show_contacts(void)
{
	int index;
	
	if (this->ContactsCount == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return ;
	}
	show_header();
	index = 0;
	while (index < this->ContactsCount)
	{
		std::cout << "|" << index << "         ";
		this->Contacts[index++].preview();
	}
	while (index < 0 || index >= this->ContactsCount)
	{
		std::cout << "Enter an index to show all contact details: ";
		if (!(std::cin >> index) || index < 0 || index >= this->ContactsCount)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index!\n";
			index = -42;
		}
		else
			this->Contacts[index].print_contact();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

