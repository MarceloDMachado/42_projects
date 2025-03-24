/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:48:10 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/24 12:51:08 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Contact.hpp"
#include "../inc/phonebook.h"

const char	*Contact::get_name(void)
{
	return (this->Name);
}

void	Contact::set_name(const char *name)
{
	this->Name = name;
}

const char	*Contact::get_phone(void)
{
	return (this->Phone);
}

void	Contact::set_phone(const char *phone)
{
	this->Phone = phone;
}
