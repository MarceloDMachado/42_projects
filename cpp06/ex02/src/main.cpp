/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:20:45 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/27 15:31:12 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../inc/Base.hpp"
#include "../inc/Functions.h"

int main(void)
{
    int i;
    
    std::srand(static_cast<unsigned>(std::time(NULL)));
	
    i= 0;
    while (i < 9)
    {
        std::cout << "\nTest " << i + 1 << ":" << std::endl;
        
        Base* ptr = generate();
        
        std::cout << "Pointer identification: ";
        identify(ptr);
        
        std::cout << "Reference identification: ";
        identify(*ptr);
        
        delete ptr;
        
        i++;
    }
    return (0);
}
