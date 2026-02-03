/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:54:03 by madias-m          #+#    #+#             */
/*   Updated: 2026/02/02 21:30:57 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME__HPP
# define PMERGEME__HPP

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <utility>

class   PmergeMe
{
	private:
	
		std::vector<int>			_vect;
		std::deque<int>				_deq;
		size_t						_level;

		
		void						vectorMerge(void);
		void						vectorInsert(void);
		void						vectorInsertions(std::vector<int> &main, const size_t &index);
		std::vector<int>::iterator	vectorBinarySearch(std::vector<int> &main, const int &target, const size_t &length);
		
		void						dequeInsert(void);
		void						dequeMerge(void);
		void						dequeInsertions(std::deque<int> &main, const size_t &index);
		std::deque<int>::iterator	dequeBinarySearch(std::deque<int> &main, const int &target, const size_t &length);
		
		void						parseInput(char **list);
		std::pair<int, int>			jacobSthal(const int & value);
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe&					operator=(const PmergeMe &other);
		~PmergeMe(void);
		
		void						sort(char **list);
};

template <typename C>
void print_container(const C &container)
{
    for (typename C::size_type i = 0; i < container.size(); i++) {
        std::cout << container[i];
        if (i + 1 < container.size())
            std::cout << " ";
    }
	std::cout << std::endl;
}

template <typename C>
void print_status(const C &container, const std::string &name, const std::pair<std::clock_t, double> &clock)
{
	std::cout
		<< "Time to process a range of " << container.size()
		<< " elements with " << name
		<< " : " << std::fixed << std::setprecision(5)
		<< clock.second / CLOCKS_PER_SEC << " us"
		<< std::endl;
}

#endif