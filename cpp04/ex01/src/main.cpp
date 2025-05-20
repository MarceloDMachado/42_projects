/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:39:45 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/20 00:37:27 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* cat = new Cat();
        const Animal* dog = new Dog();
        
        std::cout << "The Cat makes: ";
        cat->makeSound();
        std::cout << "The Dog makes: ";
        dog->makeSound();
        
        delete cat;
        delete dog;
    }
    return 0;
}