/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:01:59 by madias-m          #+#    #+#             */
/*   Updated: 2025/09/02 14:48:49 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN__HPP
# define SPAN__HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
	unsigned int		MaxSize;
	std::vector<int>	Values;

public:
	Span(void);
	Span(unsigned int n);
	Span(Span const &other);
	Span &operator=(Span const &other);
	~Span(void);
	void addNumber(int number);
	unsigned int shortestSpan(void) const throw(std::logic_error);
	unsigned int longestSpan(void) const throw(std::logic_error);

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end) throw(std::overflow_error)
	{
		if (Values.size() + std::distance(begin, end) > MaxSize)
			throw std::overflow_error("Cannot add more elements.");
		Values.insert(Values.end(), begin, end);
	}
};

#endif
