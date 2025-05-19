/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:54:36 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/19 18:48:12 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(Dog const& other);
        Dog& operator=(Dog const& other);
        ~Dog(void);
		void	makeSound(void) const;

};

#endif
