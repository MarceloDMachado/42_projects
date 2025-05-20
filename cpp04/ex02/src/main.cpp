/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:39:45 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/20 15:43:38 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"


int main()
{
    {
        std::cout << YELLOW << "======Creating a Dog and a Cat======" << RESET << std::endl;
        const Cat* cat = new Cat();
        const AAnimal* dog = new Dog();
        
        std::cout << "The Cat makes: ";
        cat->makeSound();
        std::cout << "The Dog makes: ";
        dog->makeSound();
        
        std::cout << YELLOW << "======Creating a copy of Cat======" << RESET << std::endl;
        Cat *cat_copy = new Cat(*cat);
        std::cout << YELLOW << "======Deleting the copy of Cat======" << RESET << std::endl;
        delete cat_copy;
        
        std::cout << YELLOW << "======Checking if original Cat's brain is ok======" << RESET << std::endl;
        std::cout << cat->getBrain().getIdeas()[10] << std::endl;

        std::cout << YELLOW << "======Deleting Dog and original Cat======" << RESET << std::endl;
        delete cat;
        delete dog;
    }
    return 0;
}