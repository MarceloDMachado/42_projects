/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:42:01 by madias-m          #+#    #+#             */
/*   Updated: 2026/01/07 08:24:51 by madias-m         ###   ########.fr       */
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
		RPN(void);
		RPN(std::string valuesString);
		RPN(RPN const& other);
		RPN	operator=(RPN const& other);
		~RPN(void);
		
};

#endif
