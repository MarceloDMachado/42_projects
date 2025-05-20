/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:41:00 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/20 15:26:07 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    int i;

    i = 99;
    while (i >= 0)
        this->ideas[i--] = "An empty Idea";
    std::cout << "A brain has been created." << std::endl;
}

Brain::Brain(Brain const& other)
{
    *this = other;
    std::cout << "A brain has been created by copy." << std::endl;
}

Brain&	Brain::operator=(Brain const& other)
{
	int	i;
	if (this != &other)
	{
		i = 99;
		while (i >= 0)
		{
			this->ideas[i] = other.ideas[i];
			i--;
		}
	}
	std::cout << "A Brain has been created by attribution" << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "A brain has been deleted" << std::endl;
}

std::string*	Brain::getIdeas(void)
{
	return (this->ideas);
}
