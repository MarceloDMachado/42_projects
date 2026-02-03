/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:53:41 by madias-m          #+#    #+#             */
/*   Updated: 2026/02/02 21:46:54 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void):_level(1) {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe&PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
		this->_level = other._level;
	return (*this);
}

PmergeMe::~PmergeMe(void) {}

std::pair<int, int>			PmergeMe::jacobSthal(const int &value)
{
	if (value <= 0)
		return (std::make_pair(0, 0));
	if (value == 1)
		return (std::make_pair(0, 1));

	int	first = 0;
	int second = 1;
	int	calc;

	for (int i = 2; i <= value; ++i)
	{
		calc = first * 2 + second;
		first = second;
		second = calc;
	}
	return (std::make_pair(first, second));
}

void						PmergeMe::parseInput(char **list)
{
	while (*list)
	{
		std::string	value = *list;
		if (value.empty())
			throw std::runtime_error("invalid input");
		if (value.find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error("invalid input");
		int			number = std::strtod(value.c_str(), NULL);
		
		this->_vect.push_back(number);
		this->_deq.push_back(number);
		list++;
	}
}

void						PmergeMe::sort(char **list)
{
	this->_vect.clear();
	this->_deq.clear();
	this->parseInput(list);
	
	std::pair<std::clock_t, double>	vectorClock;
	std::pair<std::clock_t, double>	dequeClock;

	std::cout << "Before:\t";
	print_container(this->_vect);

	vectorClock.first = std::clock();
	this->vectorMerge();
	vectorClock.second = static_cast<double>(std::clock() - vectorClock.first);
	
	dequeClock.first = std::clock();
	dequeMerge();
	dequeClock.second = static_cast<double>(std::clock() - dequeClock.first);

	std::cout << "After:\t"; 
	print_container(this->_vect);

	print_status(this->_vect, "std::vector<int>", vectorClock);
	print_status(this->_deq, "std::deque<int>", dequeClock);
}

/** VECTOR */

std::vector<int>::iterator	PmergeMe::vectorBinarySearch(std::vector<int> &main, const int &target, const size_t &length)
{
	size_t	low = 0;
	size_t	pos = 0;
	size_t	high = length / this->_level - 1;
	
	while (low <= high)
	{
		size_t	mid = low + (high - low) / 2;
		if (mid > length)
			return (main.begin());
		pos = (mid == 0) ? this->_level - 1 : mid * this->_level - 1;
		if (main[pos] == target)
			return (main.begin() + (mid * this->_level));
		if (main[pos] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (main[pos + this->_level] < target)
		return (main.begin() + (low * this->_level));
	return (main.begin() + (low * this->_level - this->_level));
}

void						PmergeMe::vectorInsertions(std::vector<int> &main, const size_t &index)
{
	if (main.size() >= this->_vect.size() / this->_level * this->_level)
		return ;
	std::pair<int, int>	jacob = this->jacobSthal(index);
	size_t				inserts = jacob.second - jacob. first;
	size_t				actual_b = jacob.second + 1;
	for (int i = inserts; i > 0; --i)
	{
		size_t	j = (--actual_b * 2 - 1) * this->_level - 1;
		if (j >= this->_vect.size())
			continue ;
		size_t						total_as = this->_vect.size() / 2 / this->_level;
		size_t						ignore = total_as - actual_b + 1;
		size_t						limit = main.size() - ignore;
		std::vector<int>::iterator	main_it = this->vectorBinarySearch(main, this->_vect[j], limit);
		std::vector<int>::iterator	it = this->_vect.begin();
		
		main.insert(main_it, it + j - this->_level + 1, it + j + 1);
	}
	this->vectorInsertions(main, index + 1);
}

void						PmergeMe::vectorInsert(void)
{
	std::vector<int>			main;
	std::vector<int>::iterator	it = this->_vect.begin();
	size_t						pair = this->_level * 2;
	size_t						size = (this->_vect.size() / this->_level) * this->_level;
	
	main.insert(main.end(), this->_vect.begin(), this->_vect.begin() + pair);
	for (size_t i = pair * 2 - 1; i < this->_vect.size(); i += pair)
		main.insert(main.end(), it + i + 1 - this->_level, it + i + i);
	this->vectorInsertions(main, 3);
	main.insert(main.end(), this->_vect.begin() + size, this->_vect.end());
	this->_vect = main;
}

void						PmergeMe::vectorMerge(void)
{
	size_t	pair = this->_level * 2;

	if (pair > this->_vect.size())
		return ;
	for (size_t i = pair - 1; i < this->_vect.size(); i += pair)
	{
		if (this->_vect[i - this->_level] <= this->_vect[i])
			continue ;
		size_t a = i + 1 - pair;
		size_t b = i + 1 - this->_level;
		std::vector<int>::iterator it = this->_vect.begin();
		std::swap_ranges(it + a, it + b, it + b);
	}
	this->_level *= 2;
	this->vectorMerge();

	this->_level /= 2;
	this->vectorInsert();
}

/**DEQUE */

std::deque<int>::iterator	PmergeMe::dequeBinarySearch(std::deque<int> &main, const int &target, const size_t &length)
{
	size_t	low = 0;
	size_t	high = length / this->_level - 1;
	size_t	pos = 0;

	while (low <= high)
	{
		size_t	mid = low + (high - low) / 2;
		if (mid > length)
			return main.begin();
		pos	= (mid == 0) ? this->_level - 1 : mid * this->_level - 1;
		if (main[pos] == target)
			return main.begin() + (mid * this->_level);
		if (main[pos] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (main[pos + this->_level] < target)
		return main.begin() + (low * this->_level);
	return main.begin() + (low * this->_level - this->_level);
}

void						PmergeMe::dequeInsertions(std::deque<int> &main, const size_t &index)
{
	if (main.size() >= this->_deq.size() / this->_level * this->_level)
		return ;
	std::pair<int, int> jacob = this->jacobSthal(index);
	size_t				inserts = jacob.second - jacob.first;
	size_t				actual_b = jacob.second + 1;
	
	for (int i = inserts; i > 0; --i)
	{
		actual_b--;
		size_t	j = (actual_b * 2 - 1) * this->_level - 1;
		if (j >= this->_deq.size())
			continue ;
		std::deque<int>::iterator	mit;
		std::deque<int>::iterator	it = this->_deq.begin();
		size_t	total_as = this->_deq.size() / 2 / this->_level;
		size_t	ignore = total_as = actual_b + 1;
		size_t	limit = main.size() - ignore;
		
		mit = this->dequeBinarySearch(main, this->_deq[j], limit);
		main.insert(mit, it + j - this->_level + 1, it + j + 1);
	}
	this->dequeInsertions(main, index + 1);
}

void						PmergeMe::dequeInsert(void)
{
	std::deque<int>::iterator	it = this->_deq.begin();
	std::deque<int>				main;
	size_t						pair = this->_level * 2;
	size_t						size = this->_deq.size() / this->_level * this->_level;
	
	main.insert(main.end(), this->_deq.begin(), this->_deq.begin() + pair);
	for (size_t i = pair * 2 - 1; i < this->_deq.size(); i += pair)
		main.insert(main.end(), it + i + 1 - this->_level, it + i + 1);
	this->dequeInsertions(main, 3);
	main.insert(main.end(), this->_deq.begin() + size, this->_deq.end());
	this->_deq = main;
}

void						PmergeMe::dequeMerge(void)
{
	size_t	pair = this->_level * 2;
	
	if (pair > this->_deq.size())
		return ;
	for (size_t i = pair - 1; i < this->_deq.size(); i += pair)
	{
		if (this->_deq[i - this->_level] <= this->_deq[i])
			continue ;
		size_t						a = i + 1 - pair;
		size_t						b = i + 1 - this->_level;
		std::deque<int>::iterator	it = this->_deq.begin();
		std::swap_ranges(it + a, it + b, it + b);
	}
	this->_level *= 2;
	this->dequeMerge();

	this->_level /= 2;
	this->dequeInsert();
}
