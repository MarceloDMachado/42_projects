/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:30:19 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/15 13:46:13 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>

int main( void ) {
    
    std::cout << "==========SUBJECT========" << std::endl;
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << "a: " << a << std::endl;
        std::cout << "++a: " << ++a << std::endl;
        std::cout << "a: " << a << std::endl;
        std::cout << "a++: " << a++ << std::endl;
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "max(a, b): " << Fixed::max( a, b ) << std::endl;
    }
    
    std::cout << "=========================" << std::endl;
    {
        Fixed c = Fixed(15.03f);
        Fixed d = Fixed(2.33f);
        std::cout << "c: " << c << std::endl;
        std::cout << "d: " << d << std::endl;
        std::cout << "c / d: " << c / d << std::endl;
        std::cout << "c * d: " << c * d << std::endl;
        std::cout << "c + d: " << c + d << std::endl;
        std::cout << "c - d: " << c - d << std::endl;
        std::cout << "++d: " << ++d << std::endl;
    }
    return 0;
}
