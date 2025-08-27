/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:03:14 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/27 11:19:23 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER__HPP
# define SCALARCONVERTER__HPP

#include <string>
#include <iostream>

class ScalarConverter {
    private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter(void);
		static bool		isChar(const std::string &str);
		static bool		isInt(const std::string &str);
		static bool		isFloat(const std::string &str);
		static bool		isDouble(const std::string &str);
		static void		toChar(const std::string &str);
		static void		toInt(const std::string &str);
		static void		toFloat(const std::string &str);
		static void		toDouble(const std::string &str);

	public:
		static void    convert(const std::string &str);
};

#endif
