/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:42:01 by madias-m          #+#    #+#             */
/*   Updated: 2026/01/07 09:25:48 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN__HPP
# define RPN__HPP

#include <stack>
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>

class	RPN
{
	public:
		RPN(void);
		RPN(RPN const& other);
		RPN	operator=(RPN const& other);
		~RPN(void);
		int	calcRPN(const std::string& valuesString) const;
};

#endif
