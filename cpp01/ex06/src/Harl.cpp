/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:46:38 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/07 14:00:42 by madias-m         ###   ########.fr       */
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

std::string to_lower(const char *str)
{
    std::string result;
    
    while (*str)
        result.push_back(::tolower(*str++));
    return (result);
}

int     get_index(std::string level)
{
    int i;
    std::string methods[5] = {"debug", "info", "warning", "error"};

    i = 0;
    while (i < 4)
    {
        if (methods[i].compare(level) == 0)
            return (i);
        i++;
    }
    return (-1);
}

void    Harl::complain(std::string level)
{
    int index;
    static std::map<std::string, void (Harl::*)(void)> myPrivateMethodsMap;
    myPrivateMethodsMap.insert(std::make_pair("debug", &Harl::debug));
    myPrivateMethodsMap.insert(std::make_pair("info", &Harl::info));
    myPrivateMethodsMap.insert(std::make_pair("warning", &Harl::warning));
    myPrivateMethodsMap.insert(std::make_pair("error", &Harl::error));
    
    level = to_lower(level.c_str());
    if (myPrivateMethodsMap.find(level) == myPrivateMethodsMap.end())
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return ;
    }
    index = get_index(level);
    switch (index)
    {
        case 0:
            (this->*myPrivateMethodsMap["debug"])();
            index++;
        case 1:
            (this->*myPrivateMethodsMap["info"])();
            index++;
        case 2:
            (this->*myPrivateMethodsMap["warning"])();
            index++;
        case 3:
            (this->*myPrivateMethodsMap["error"])();
            index++;
    }
}
