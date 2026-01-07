/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:42:09 by madias-m          #+#    #+#             */
/*   Updated: 2026/01/07 09:38:39 by madias-m         ###   ########.fr       */
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

RPN RPN::operator=(RPN const& other)
{
	(void) other;
    return (*this);
}

RPN::~RPN(void) { }

bool	isOp(char c)
{
	return (strchr("/*+-", c));
}

int		getResult(char op, int a, int b)
{
	switch (op) 
	{
    	case '+':
			return (a + b);
    	case '-':
			return (a - b);
    	case '*':
			return (a * b);
    	case '/':
		{
        	if (!a || !b) 
				throw std::runtime_error("Error");
        	return (a / b);
		}
    }
    throw std::runtime_error("Error");
}

int	RPN::calcRPN(const std::string& valuesString) const
{
	if (valuesString.empty())
		throw std::runtime_error("Error");
	
	char				validChars[11] = "0123456789";
	std::stringstream	iss(valuesString);
	std::stack<int>		stack;
	std::string 		token;
	
	while (iss >> token)
	{
		char	token_char = token.c_str()[0];
		if (token.size() == 1 && strchr(validChars, token_char))
			stack.push(token_char - 48);
		else if (token.size() == 1 && isOp(token_char))
		{
			if (stack.size() < 2) 
				throw std::runtime_error("Error");
			int	b = stack.top();
			stack.pop();
			int	a = stack.top();
			stack.pop();
			int	result = getResult(token_char, a, b);
			stack.push(result);
		}
		else
			throw std::runtime_error("Error");
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error");
	return (stack.top());
}





