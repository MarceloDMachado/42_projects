/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:50:26 by madias-m          #+#    #+#             */
/*   Updated: 2025/12/10 17:30:20 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->Database = other.Database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
    
}

void BitcoinExchange::loadData(const std::string &filename)
{
	size_t			delimiter;
	float			rate;
	char			remainingContent;
	std::string		line;
	std::ifstream	file(filename.c_str());
	std::string		date;
	std::string		rateStr;
	
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		delimiter = line.find(",");
		if (delimiter == std::string::npos)
			continue ;
		date = line.substr(0, delimiter);
		rateStr = line.substr(delimiter + 1);
		std::istringstream iss(rateStr);
		if (!(iss >> rate))
		{
			std::cerr << "Warning: invalid rate in database: " << rateStr << std::endl;
			continue ;
		}
		if (iss >> remainingContent)
		{
			std::cerr << "Warning: unexpected characters in rate: " << rateStr << std::endl;
			continue ;
		}
		this->Database[date] = rate;
	}
	file.close();
}

bool isLeapYear(int year) {
    if (year % 400 == 0)
        return (true);
    if (year % 100 == 0)
        return (false);
    if (year % 4 == 0)
        return (true);
    return (false);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	int	year;
	int month;
	int day;
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(date[i]))
			return (false);
	}

	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());

	if (isLeapYear(year))
		daysInMonth[2] = 29;
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > daysInMonth[month])
		return (false);
	return (true);
}

bool BitcoinExchange::isValidValue(const std::string &value, float &val) const
{
	std::istringstream iss(value);

	char	remaining;
	
	if (!(iss >> val))
		return (false);
	if (iss >> remaining)
		return (false);
	if (val < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}

	if (val >= (float) 2147483647)
	{
		std::cerr << "Error: too large a number." << std::endl;	
		return (false);
	}
	return (true);
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
	if (this->Database.empty())
		return (0.0f);
	std::map<std::string, float>::const_iterator it = this->Database.lower_bound(date);
	if (it != this->Database.end() && it->first == date)
		return (it->second);
	if (it != this->Database.begin())
		return ((--it)->second);
	return (0.0f);
}

void	BitcoinExchange::processInput(const std::string &fileName)
{
	std::ifstream fileStream(fileName.c_str());
	
	if (!fileStream.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string	line;
	std::getline(fileStream, line);
	while (std::getline(fileStream, line))
	{
		if (line.empty())
			continue;
		size_t	delimiterPos = line.find(" | ");
		if (delimiterPos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		float		value;
		std::string	date = line.substr(0, delimiterPos);
		std::string	valueStr = line.substr(delimiterPos + 3);
		
		if (!isValidDate(date) || !isValidValue(valueStr, value))
			continue;
		std::cout << date << " => " << value << " = " << (value * getExchangeRate(date)) << std::endl;
	}
	fileStream.close();
}
