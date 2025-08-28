/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:56:25 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/28 09:57:17 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../inc/Array.hpp"

int main()
{
    std::cout << "---- Test 1: Default constructor ----" << std::endl;
    Array<int> a1;
    std::cout << "Size of a1: " << a1.size() << std::endl;

    std::cout << "\n---- Test 2: Constructor with size ----" << std::endl;
    Array<int> a2(5);
    std::cout << "Size of a2: " << a2.size() << std::endl;
    for (unsigned int i = 0; i < a2.size(); i++)
        std::cout << "a2[" << i << "] = " << a2[i] << std::endl;

    std::cout << "\n---- Test 3: Writing and reading elements ----" << std::endl;
    for (unsigned int i = 0; i < a2.size(); i++)
        a2[i] = (i + 1) * 10;
    for (unsigned int i = 0; i < a2.size(); i++)
        std::cout << "a2[" << i << "] = " << a2[i] << std::endl;

    std::cout << "\n---- Test 4: Const access ----" << std::endl;
    const Array<int> a3 = a2;
    for (unsigned int i = 0; i < a3.size(); i++)
        std::cout << "a3[" << i << "] = " << a3[i] << std::endl;

    std::cout << "\n---- Test 5: Copy constructor ----" << std::endl;
    Array<int> a4(a2);
    for (unsigned int i = 0; i < a4.size(); i++)
        std::cout << "a4[" << i << "] = " << a4[i] << std::endl;

    std::cout << "\n---- Test 6: Assignment operator ----" << std::endl;
    Array<int> a5;
    a5 = a2;
    for (unsigned int i = 0; i < a5.size(); i++)
        std::cout << "a5[" << i << "] = " << a5[i] << std::endl;

    std::cout << "\n---- Test 7: Out of bounds exception ----" << std::endl;
    try
    {
        std::cout << "Trying to access a2[10]..." << std::endl;
        std::cout << a2[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n---- Test 8: Array with std::string ----" << std::endl;
    Array<std::string> a6(3);
    a6[0] = "Hello";
    a6[1] = "World";
    a6[2] = "Array Template";
    for (unsigned int i = 0; i < a6.size(); i++)
        std::cout << "a6[" << i << "] = " << a6[i] << std::endl;

    return 0;
}

