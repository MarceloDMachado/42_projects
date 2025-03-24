/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:48:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/24 14:32:56 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.h"

std::string	Contact::get_name(void)
{
	return (this->Name);
}

void	Contact::set_name(std::string name)
{
	this->Name = name;
}

std::string	Contact::get_phone(void)
{
	return (this->Phone);
}

void	Contact::set_phone(std::string phone)
{
	this->Phone = phone;
}
