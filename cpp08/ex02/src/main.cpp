/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:42:47 by madias-m          #+#    #+#             */
/*   Updated: 2025/09/02 19:59:59 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

#include <iostream>
#include <string>
#include <cassert>
#include "MutantStack.hpp"

void test_basic_push_pop() {
    MutantStack<int> ms;
    ms.push(10);
    ms.push(20);
    ms.push(30);

    assert(ms.top() == 30);
    ms.pop();
    assert(ms.top() == 20);
    assert(ms.size() == 2);

    std::cout << "[OK] test_basic_push_pop\n";
}

void test_iteration() {
    MutantStack<int> ms;
    for (int i = 1; i <= 5; i++)
        ms.push(i * 10);

    int expected = 10;
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        assert(*it == expected);
        expected += 10;
    }
    std::cout << "[OK] test_iteration\n";
}

void test_reverse_iteration() {
    MutantStack<int> ms;
    for (int i = 1; i <= 3; i++)
        ms.push(i);

    int expected = 3;
    for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit) {
        assert(*rit == expected);
        expected--;
    }
    std::cout << "[OK] test_reverse_iteration\n";
}

void test_const_iterators() {
    MutantStack<std::string> ms;
    ms.push("A");
    ms.push("B");
    ms.push("C");

    const MutantStack<std::string> cms(ms);

    MutantStack<std::string>::const_iterator it = cms.begin();
    assert(*it == "A");

    MutantStack<std::string>::const_reverse_iterator rit = cms.rbegin();
    assert(*rit == "C");

    std::cout << "[OK] test_const_iterators\n";
}

void test_copy_and_assignment() {
    MutantStack<int> ms1;
    ms1.push(100);
    ms1.push(200);

    MutantStack<int> ms2(ms1);
    assert(ms2.top() == 200);

    MutantStack<int> ms3;
    ms3 = ms1;
    assert(ms3.top() == 200);

    std::cout << "[OK] test_copy_and_assignment\n";
}

int main() {
    test_basic_push_pop();
    test_iteration();
    test_reverse_iteration();
    test_const_iterators();
    test_copy_and_assignment();

    return (0);
}

