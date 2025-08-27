/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:35:39 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/27 14:59:55 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Serializer.hpp"

int main(void)
{
    Data originalData;
    originalData.id = 42;
    originalData.name = "Hello, World!";
    
    std::cout << "\nORIGINAL VALUES:" << std::endl;
    std::cout << "Original Address: " << &originalData << std::endl;
    std::cout << "Original ID: " << originalData.id << std::endl;
    std::cout << "Original Name: " << originalData.name << std::endl;
    
    std::cout << "\nSERIALIZED VALUE (INT):" << std::endl;
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    
    std::cout << "\nORIGINAL VALUES RECOVERD BY DESERIALIZE:" << std::endl;
    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Address: " << deserialized << std::endl;
    std::cout << "Deserialized ID: " << deserialized->id << std::endl;
    std::cout << "Deserialized Name: " << deserialized->name << std::endl;
    
    return (0);
}
