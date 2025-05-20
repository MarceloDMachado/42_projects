/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:40:30 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/20 15:42:00 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal(void);
		AAnimal(AAnimal const& other);
		AAnimal& operator=(AAnimal const& other);
		virtual ~AAnimal(void);
		virtual void		makeSound(void) const = 0;
		std::string	getType(void) const;
};
#endif
