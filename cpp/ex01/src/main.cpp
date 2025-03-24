/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:40:24 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/24 12:47:34 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.h"

int main(void)
{
	Contact cont;

	cont.set_name("Marcelo");
	cont.set_phone("11949335709");
	std::cout << "Nome: " << cont.get_name() << std::endl;
	std::cout << "Phone: " << cont.get_phone() << std::endl;
	return (0);
}

