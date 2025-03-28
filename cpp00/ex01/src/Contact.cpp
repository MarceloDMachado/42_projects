/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:48:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/26 14:18:12 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.h"


std::string	Contact::get_first_name(void)
{
	return (this->First_Name);
}

void	Contact::set_first_name(std::string firstName)
{
	this->First_Name = firstName;
}

std::string Contact::get_last_name(void)
{
	return (this->Last_Name);
}

void	Contact::set_last_name(std::string lastName)
{
	this->Last_Name = lastName;
}

std::string Contact::get_nickname(void)
{
	return (this->Nickname);
}

void	Contact::set_nickname(std::string nickname)
{
	this->Nickname = nickname;
}

std::string	Contact::get_phone_number(void)
{
	return (this->Phone_Number);
}

void	Contact::set_phone_number(std::string phone)
{
	this->Phone_Number = phone;
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->Darkest_Secret);
}

void	Contact::set_darkest_secret(std::string darkestSecret)
{
	this->Darkest_Secret = darkestSecret;
}

static void	trunc(std::string value)
{
	int i;

	i = 0;
	std::cout << "|";
	while (value.c_str()[i] && i < 9)
		std::cout << value.c_str()[i++];
	if (value.c_str()[i])
	{
		std::cout << '.';
		i++;
	}
	while (i++ <= 9)
		std::cout << ' ';
}

void	Contact::preview(void)
{
	trunc(this->First_Name);
	trunc(this->Last_Name);
	trunc(this->Nickname);
	std::cout << "|" << std::endl;
}

void	Contact::print_contact(void)
{
	std::cout << "FIRST NAME: " << this->First_Name << std::endl;
	std::cout << "LAST NAME: " << this->Last_Name << std::endl;
	std::cout << "NICKNAME: " << this->Nickname << std::endl;
	std::cout << "PHONE NUMBER: " << this->Phone_Number << std::endl;
	std::cout << "DARKEST SECRET: " << this->Darkest_Secret << std::endl;
}
