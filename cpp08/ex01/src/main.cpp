/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:28:18 by madias-m          #+#    #+#             */
/*   Updated: 2025/09/02 14:56:54 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

void test_basic_add_and_span() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    assert(sp.shortestSpan() == 2);  // 9 e 11
    assert(sp.longestSpan() == 14);  // 17 - 3
    std::cout << "[OK] test_basic_add_and_span\n";
}

void test_overflow_exception() 
{
    Span sp(2);
    sp.addNumber(1);
    sp.addNumber(2);
    try {
        sp.addNumber(3);
    } catch (const std::overflow_error &e) {
        std::cout << "[OK] test_overflow_exception (" << e.what() << ")\n";
    }
}

void test_shortest_longest_exceptions()
{
    Span sp(1);
    sp.addNumber(42);

    try {
        sp.shortestSpan();
        assert(false);
    } catch (const std::logic_error &e) {
        std::cout << "[OK] test_shortestSpan_exception (" << e.what() << ")\n";
    }

    try {
        sp.longestSpan();
        assert(false);
    } catch (const std::logic_error &e) {
        std::cout << "[OK] test_longestSpan_exception (" << e.what() << ")\n";
    }
}

void test_negative_and_large_numbers() {
    Span sp(4);
    sp.addNumber(-100);
    sp.addNumber(50);
    sp.addNumber(200);
    sp.addNumber(-150);

    assert(sp.shortestSpan() == 50);   // -150 e -100
    assert(sp.longestSpan() == 350);   // 200 - (-150)
    std::cout << "[OK] test_negative_and_large_numbers\n";
}

void test_large_input() {
    unsigned int n = 10000;
    Span sp(n);

    for (unsigned int i = 0; i < n; i++)
        sp.addNumber(i);

    assert(sp.shortestSpan() == 1);       // sempre diferença de 1
    assert(sp.longestSpan() == n - 1);    // 9999 - 0
    std::cout << "[OK] test_large_input (10k numbers)\n";
}

int main() {
    test_basic_add_and_span();
    test_overflow_exception();
    test_shortest_longest_exceptions();
    test_negative_and_large_numbers();
    test_large_input();

    std::cout << "✅ Working Perfectly!\n";
    return 0;
}

