/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:42:01 by madias-m          #+#    #+#             */
/*   Updated: 2025/09/09 11:43:09 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN__HPP
# define RPN__HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class	RPN
{
	private:
		std::stack<char>	ValueStack;
	public:
		RPN::RPN(void);
		RPN::RPN(std::string valuesString);
		RPN::RPN(RPN const& other);
		RPN	RPN::operator=(RPN const& other);
		RPN::~RPN(void);
		
};

#endif
