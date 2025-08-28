/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:10:15 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/28 15:16:52 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include "easyfind.hpp"

template<typename T>
void testEasyFind(T &container, int value, const std::string &containerName)
{
    typename T::iterator it = easyfind(container, value);
    if (it != container.end())
        std::cout << "Value " << value << " found in " << containerName 
                  << " at position (iterator deref): " << *it << std::endl;
    else
        std::cout << "Value " << value << " not found in " << containerName << std::endl;
}

int main()
{
    std::cout << "---- Test 1: std::vector<int> ----" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    testEasyFind(vec, 20, "vector");
    testEasyFind(vec, 40, "vector");

    std::cout << "\n---- Test 2: std::list<int> ----" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    testEasyFind(lst, 15, "list");
    testEasyFind(lst, 99, "list");

    std::cout << "\n---- Test 3: std::deque<int> ----" << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    testEasyFind(deq, 100, "deque");
    testEasyFind(deq, 500, "deque");

    std::cout << "\n---- Test 4: std::set<int> ----" << std::endl;
    std::set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    testEasyFind(st, 2, "set");
    testEasyFind(st, 10, "set");

    std::cout << "\n---- Test 5: Empty container ----" << std::endl;
    std::vector<int> emptyVec;
    testEasyFind(emptyVec, 1, "empty vector");

    return 0;
}
