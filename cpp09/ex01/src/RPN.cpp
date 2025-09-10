/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:42:09 by madias-m          #+#    #+#             */
/*   Updated: 2025/09/10 11:37:52 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN(void)
{
    
}

RPN::RPN(RPN const& other)
{
	*this = other;
}

RPN::RPN(std::string valuesString)
{
	std::stringstream	iss(valuesString);
    char*				validChars[2] = {"0123456789", "/*+-"};
    char    			index = 0;
	char				current;

	while (iss >> current)
	{
		if (strchr(validChars[index], current))
			this->ValueStack.push(current);
	}

	
	
}


RPN RPN::operator=(RPN const& other)
{
    if (this != &other)
        this->ValueStack = other.ValueStack;
    return (*this);
}

RPN::~RPN(void)
{
    
}


