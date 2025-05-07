/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:46:38 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/06 22:35:35 by madias-m         ###   ########.fr       */
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

void    Harl::complain(std::string level)
{
    int index;
    std::map<std::string, void (Harl::*)(void)> myPrivateMethodsMap;
    // myPrivateMethodsMap["debug"] = &Harl::debug;
    // myPrivateMethodsMap["info"] = &Harl::info;
    // myPrivateMethodsMap["warning"] = &Harl::warning;
    // myPrivateMethodsMap["error"] = &Harl::error;

    myPrivateMethodsMap.insert(std::make_pair("debug", &Harl::debug));
    myPrivateMethodsMap.insert(std::make_pair("info", &Harl::info));
    myPrivateMethodsMap.insert(std::make_pair("warning", &Harl::warning));
    myPrivateMethodsMap.insert(std::make_pair("error", &Harl::error));
    
    if (myPrivateMethodsMap.find(level) == myPrivateMethodsMap.end())
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return ;
    }
    
    index = std::distance(myPrivateMethodsMap.begin(), myPrivateMethodsMap.find(level));
    switch (index)
    {
        case 0:
            (this->*(myPrivateMethodsMap["debug"]))();
            index++;
        case 1:
            (this->*(myPrivateMethodsMap["info"]))();
            index++;
        case 2:
            (this->*(myPrivateMethodsMap["warning"]))();
            index++;
        case 3:
            (this->*(myPrivateMethodsMap["error"]))();
            index++;
    }
}
