/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:18:25 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/27 15:29:22 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base*   generate(void)
{
    int random = std::rand() % 3;
    
    switch (random) {
        case 0: 
            return new A();
        case 1: 
            return new B();
        case 2: 
            return new C();
        default: 
            return (NULL);
    }
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
    try {
        (void) dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (std::exception& e) {}
    
    try {
        (void) dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (std::exception& e) {}
    
    try {
        (void) dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::exception& e) {}
}