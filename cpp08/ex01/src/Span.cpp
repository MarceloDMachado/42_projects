/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:13:25 by madias-m          #+#    #+#             */
/*   Updated: 2025/09/02 14:55:16 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(void)
{
	this->MaxSize =0;
}

Span::Span(unsigned int n)
{
	this->MaxSize = n;
}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->MaxSize = other.MaxSize;
		this->Values = other.Values;
	}
	return (*this);
}

Span::~Span(void)
{
	
}

void Span::addNumber(int number)
{
	if (this->Values.size() >= this->MaxSize)
		throw std::overflow_error("Cannot add more elements.");
	this->Values.push_back(number);
}

unsigned int Span::shortestSpan(void) const throw(std::logic_error)
{
	if (this->Values.size() <= 1)
		throw std::logic_error("Cannot find a spam without 2 numbers at least");

	std::vector<int> sortedValues = this->Values;
	std::sort(sortedValues.begin(), sortedValues.end());

	unsigned int min = std::numeric_limits<unsigned int>::max();
	
	for (size_t i = 1; i < sortedValues.size(); ++i)
	{
		unsigned int currentSpan = sortedValues[i] - sortedValues[i - 1];
		if (currentSpan < min)
			min = currentSpan;
	}
	
	return (min);
}

unsigned int Span::longestSpan(void) const throw(std::logic_error)
{
	if (this->Values.size() <= 1)
		throw std::logic_error("Cannot find a spam without 2 numbers at least");

	int min = *std::min_element(this->Values.begin(), this->Values.end());
	int max = *std::max_element(this->Values.begin(), this->Values.end());
	
	return (max - min);
}
