/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:46:36 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/28 09:53:30 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// Function for mutable elements
template<typename T>
void printElement(T &elem)
{
    std::cout << "Element: " << elem << std::endl;
}

// Function for const elements
template<typename T>
void printConstElement(const T &elem)
{
    std::cout << "Const Element: " << elem << std::endl;
}

// Function to modify elements
void addOne(int &n)
{
    n += 1;
    std::cout << "Modified Element: " << n << std::endl;
}

// Function to uppercase strings
void toUpper(std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i)
        str[i] = std::toupper(str[i]);

    std::cout << "Modified String: " << str << std::endl;
}

int main()
{
    std::cout << "---- Test 1: Integers with const function ----" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    iter(numbers, 5, printConstElement<int>);

    std::cout << "\n---- Test 2: Integers with modification ----" << std::endl;
    iter(numbers, 5, addOne);

    std::cout << "\n---- Test 3: Strings with const function ----" << std::endl;
    std::string words[] = {"hello", "world", "iter", "test"};
    iter(words, 4, printConstElement<std::string>);

    std::cout << "\n---- Test 4: Strings with modification ----" << std::endl;
    iter(words, 4, toUpper);

    std::cout << "\n---- Test 5: Doubles with const function ----" << std::endl;
    double decimals[] = {1.1, 2.2, 3.3};
    iter(decimals, 3, printConstElement<double>);

    std::cout << "\n---- Test 6: Null safety ----" << std::endl;
    iter<int>(nullptr, 5, printElement<int>);
    iter<int>(numbers, 5, nullptr);

    return 0;
}

