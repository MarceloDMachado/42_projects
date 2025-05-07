/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:46:38 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/06 21:53:24 by madias-m         ###   ########.fr       */
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
    std::cout << "[ERROR] Example of error message" << std::endl;
}

void    Harl::complain(std::string level)
{
    std::map<std::string, void (Harl::*)(void)> myPrivateMethodsMap;
    myPrivateMethodsMap["debug"] = &Harl::debug;
    myPrivateMethodsMap["info"] = &Harl::info;
    myPrivateMethodsMap["warning"] = &Harl::warning;
    myPrivateMethodsMap["error"] = &Harl::error;

    if (myPrivateMethodsMap.find(level) != myPrivateMethodsMap.end())
        (this->*(myPrivateMethodsMap[level]))();
}
