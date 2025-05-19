/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:39:45 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/19 18:58:27 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* cat = new Cat();
        const Animal* dog = new Dog();
        
        std::cout << cat->getType() << " " << std::endl;
        std::cout << dog->getType() << " " << std::endl;
        
        cat->makeSound();
        dog->makeSound();
        meta->makeSound();
        
        delete meta;
        delete cat;
        delete dog;
    }
    
    std::cout << "====Wrong Animal Test====" << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();
        
        std::cout << cat->getType() << " " << std::endl;
        
        cat->makeSound();
        meta->makeSound();
        
        delete meta;
        delete cat;
    }
    return 0;
}