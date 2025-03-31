/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:04:46 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/31 16:01:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		*stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "str address: " << &str << std::endl;
	std::cout << "address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "address held by stringREF: " << &stringREF << std::endl;

	std::cout << "str value: " << str << std::endl;
	std::cout << "value by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value by stringREF: " << stringREF << std::endl;
	return (0);
}