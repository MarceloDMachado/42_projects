/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:40:24 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/24 14:31:28 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.h"

int main(void)
{
	Contact 	cont;
	std::string	name;
	std::string	phone;

	std::cout << "Informe o nome: ";
	std::cin >> name;
	std::cout << "Informe o numero: ";
	std::cin >> phone;
	cont.set_name(name);
	cont.set_phone(phone);
	std::cout << "Nome: " << cont.get_name() << std::endl;
	std::cout << "Phone: " << cont.get_phone() << std::endl;
	return (0);
}

