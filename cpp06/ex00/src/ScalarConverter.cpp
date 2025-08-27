/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:02:59 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/27 12:14:34 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    (void) src;
    return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

bool ScalarConverter::isChar(const std::string &str) {
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isInt(const std::string &str) {
    size_t i = 0;
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (i < str.length())
	{
        if (!isdigit(str[i++]))
            return (false);
    }
    return (true);
}

bool ScalarConverter::isFloat(const std::string &str) {
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return (true);
        
    size_t i = 0;
    bool hasDecimal = false;
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (i < str.length() - 1)
	{
        if (str[i] == '.')
		{
            if (hasDecimal)
                return (false);
            hasDecimal = true;
        }
        else if (!isdigit(str[i]) && (i == (str.length() - 2) || str[i] != 'f'))
            return (false);
		i++;
    }
    return (str[str.length() - 1] == 'f' && hasDecimal);
}

bool ScalarConverter::isDouble(const std::string &str) {
    if (str == "nan" || str == "+inf" || str == "-inf")
        return (true);
        
    size_t i = 0;
    bool hasDecimal = false;
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (i < str.length()) {
        if (str[i] == '.') {
            if (hasDecimal)
                return (false);
            hasDecimal = true;
        }
        else if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (hasDecimal);
}

void ScalarConverter::toChar(const std::string &str) {
    char c = str[1];
    
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::toInt(const std::string &str) {
    long value = std::atol(str.c_str());
    
    if (value > std::numeric_limits<int>::max() || 
        value < std::numeric_limits<int>::min()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }

    int i = static_cast<int>(value);
    if (i < 32 || i > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::toFloat(const std::string &str) {
    float f;
    
    if (str == "nanf" || str == "+inff" || str == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (str == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (str == "+inff")
            f = std::numeric_limits<float>::infinity();
        else
			f = -std::numeric_limits<float>::infinity();
    }
	else {
        f = std::atof(str.c_str());
        if (f < 32 || f > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::toDouble(const std::string &str) {
    double d;
    
    if (str == "nan" || str == "+inf" || str == "-inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (str == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (str == "+inf")
            d = std::numeric_limits<double>::infinity();
        else
            d = -std::numeric_limits<double>::infinity();
    }
	else {
        d = std::atof(str.c_str());
        if (d < 32 || d > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        if (d > std::numeric_limits<int>::max() || 
            d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &str) {
    if (str.empty()) {
        std::cout << "Error: empty input" << std::endl;
        return ;
	}
	
    if (isChar(str))
        toChar(str);
    else if (isInt(str))
        toInt(str);
    else if (isFloat(str))
        toFloat(str);
    else if (isDouble(str))
        toDouble(str);
    else
        std::cout << "Error: invalid input" << std::endl;
}
