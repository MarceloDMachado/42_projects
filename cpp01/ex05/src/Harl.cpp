/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:46:38 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/10 12:52:54 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "[DEBUG] Example of debug message" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[INFO] Example of info message" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[WARNING] Example of warning message!" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ERROR] Example of error message!!!" << std::endl;
}

int		get_index(std::string *strArray, std::string find, int max)
{
	int	i;

	i = 0;
	while (i <= max)
	{
		if (strArray[i].compare(find) == 0)
			return (i);
		else
			i++;
	}
	return (-42);
}

void    Harl::complain(std::string level)
{
	int 		i;
	void		(Harl::*funcArray[4])(void) = {
		&Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string	levelArray[5] = {
        "debug",
        "info",
        "warning",
        "error"
    };
	i = get_index(levelArray, level, 3);
	if (i == -42)
		std::cout << "Error: Could not find the level: \"" << level << "\"\n";
	else
		(this->*funcArray[i])();
}
