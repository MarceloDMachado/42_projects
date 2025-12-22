/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:44:15 by madias-m          #+#    #+#             */
/*   Updated: 2025/12/11 14:39:03 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE__HPP
# define BITCOINEXCHANGE__HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
    private:
		std::map<std::string, float>	Database;
		bool							isValidDate(const std::string &date) const;
		bool							isValidValue(const std::string &value, long double &val) const;
		float							getExchangeRate(const std::string &date) const;
    public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange(void);
		void							loadData(const std::string &fileName);
		void							processInput(const std::string &fileName);
};

#endif
