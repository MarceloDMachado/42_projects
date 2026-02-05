/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:53:41 by madias-m          #+#    #+#             */
/*   Updated: 2026/02/05 13:56:49 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void):_order(1) {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe&PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
		this->_order = other._order;
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
	this->dequeMerge();
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
	size_t	high = length / this->_order - 1;
	
	while (low <= high)
	{
		size_t	mid = low + (high - low) / 2;
		if (mid > length)
			return (main.begin());
		pos = (mid == 0) ? this->_order - 1 : mid * this->_order - 1;
		if (main[pos] == target)
			return (main.begin() + (mid * this->_order));
		if (main[pos] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (main[pos + this->_order] < target)
		return (main.begin() + (low * this->_order));
	return (main.begin() + (low * this->_order - this->_order));
}

void						PmergeMe::vectorInsertions(std::vector<int> &main, const size_t &index)
{
	if (main.size() >= this->_vect.size() / this->_order * this->_order)
		return ;
	std::pair<int, int>	jacob = this->jacobSthal(index);
	size_t				inserts = jacob.second - jacob.first;
	size_t				actual_b = jacob.second + 1;
	for (int i = inserts; i > 0; --i)
	{
		size_t	j = (--actual_b * 2 - 1) * this->_order - 1;
		if (j >= this->_vect.size())
			continue ;
		size_t						total_as = this->_vect.size() / 2 / this->_order;
		size_t						ignore = total_as - actual_b + 1;
		size_t						limit = main.size() - ignore;
		std::vector<int>::iterator	main_it = this->vectorBinarySearch(main, this->_vect[j], limit);
		std::vector<int>::iterator	it = this->_vect.begin();
		
		main.insert(main_it, it + j - this->_order + 1, it + j + 1);
	}
	this->vectorInsertions(main, index + 1);
}

void						PmergeMe::vectorInsert(void)
{
	std::vector<int>			main;
	std::vector<int>::iterator	it = this->_vect.begin();
	size_t						pair = this->_order << 1;
	size_t						size = (this->_vect.size() / this->_order) * this->_order;
	
	main.insert(main.end(), this->_vect.begin(), this->_vect.begin() + pair);
	for (size_t i = pair * 2 - 1; i < this->_vect.size(); i += pair)
		main.insert(main.end(), it + i + 1 - this->_order, it + i + 1);
	this->vectorInsertions(main, 3);
	main.insert(main.end(), this->_vect.begin() + size, this->_vect.end());
	this->_vect = main;
}

void						PmergeMe::vectorMerge(void)
{
	size_t	pair = this->_order * 2;

	if (pair > this->_vect.size())
		return ;
	for (size_t i = pair - 1; i < this->_vect.size(); i += pair)
	{
		if (this->_vect[i - this->_order] <= this->_vect[i])
			continue ;
		size_t 						a = i + 1 - pair;
		size_t 						b = i + 1 - this->_order;
		std::vector<int>::iterator	it = this->_vect.begin();
		std::swap_ranges(it + a, it + b, it + b);
	}
	this->_order <<= 1;
	this->vectorMerge();

	this->_order >>= 1;
	this->vectorInsert();
}

/**DEQUE */

std::deque<int>::iterator	PmergeMe::dequeBinarySearch(std::deque<int> &main, const int &target, const size_t &length)
{
	size_t	low = 0;
	size_t	pos = 0;
	size_t	high = length / this->_order - 1;

	while (low <= high)
	{
		size_t	mid = low + (high - low) / 2;
		if (mid > length)
			return (main.begin());
		pos	= (mid == 0) ? this->_order - 1 : mid * this->_order - 1;
		if (main[pos] == target)
			return (main.begin() + (mid * this->_order));
		if (main[pos] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (main[pos + this->_order] < target)
		return (main.begin() + (low * this->_order));
	return (main.begin() + (low * this->_order - this->_order));
}

void						PmergeMe::dequeInsertions(std::deque<int> &main, const size_t &index)
{
	if (main.size() >= this->_deq.size() / this->_order * this->_order)
		return ;
	std::pair<int, int> jacob = this->jacobSthal(index);
	size_t				inserts = jacob.second - jacob.first;
	size_t				actual_b = jacob.second + 1;
	
	for (int i = inserts; i > 0; --i)
	{
		size_t	j = (--actual_b * 2 - 1) * this->_order - 1;
		if (j >= this->_deq.size())
			continue ;
		size_t						total_as = this->_deq.size() / 2 / this->_order;
		size_t						ignore = total_as - actual_b + 1;
		size_t						limit = main.size() - ignore;
		std::deque<int>::iterator	it = this->_deq.begin();
		std::deque<int>::iterator	mit;
		
		mit = this->dequeBinarySearch(main, this->_deq[j], limit);
		main.insert(mit, it + j - this->_order + 1, it + j + 1);
	}
	this->dequeInsertions(main, index + 1);
}

void						PmergeMe::dequeInsert(void)
{
	std::deque<int>				main;
	std::deque<int>::iterator	it = this->_deq.begin();
	size_t						pair = this->_order << 1;
	size_t						size = (this->_deq.size() / this->_order) * this->_order;
	
	main.insert(main.end(), this->_deq.begin(), this->_deq.begin() + pair);
	for (size_t i = pair * 2 - 1; i < this->_deq.size(); i += pair)
		main.insert(main.end(), it + i + 1 - this->_order, it + i + 1);
	this->dequeInsertions(main, 3);
	main.insert(main.end(), this->_deq.begin() + size, this->_deq.end());
	this->_deq = main;
}

void						PmergeMe::dequeMerge(void)
{
	size_t	pair = this->_order << 1;
	
	if (pair > this->_deq.size())
		return ;
	for (size_t i = pair - 1; i < this->_deq.size(); i += pair)
	{
		if (this->_deq[i - this->_order] <= this->_deq[i])
			continue ;
		size_t						a = i + 1 - pair;
		size_t						b = i + 1 - this->_order;
		std::deque<int>::iterator	it = this->_deq.begin();
		std::swap_ranges(it + a, it + b, it + b);
	}
	this->_order <<= 1;
	this->dequeMerge();

	this->_order >>= 1;
	this->dequeInsert();
}
