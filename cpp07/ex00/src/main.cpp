/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:22:37 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/27 16:28:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../inc/whatever.hpp"

// Custom struct for user-defined type tests
struct Point {
    int x, y;

    // Comparison operators (compare by squared distance to origin)
    bool operator<(const Point& other) const {
        return (x*x + y*y) < (other.x*other.x + other.y*other.y);
    }
    bool operator>(const Point& other) const {
        return (x*x + y*y) > (other.x*other.x + other.y*other.y);
    }
};

// Test runner
int main() {
    // 1. Integers
    int a = 10, b = 20;
    std::cout << "=== Integer tests ===\n";
    std::cout << "Before swap: a=" << a << " b=" << b << "\n";
    swap(a, b);
    std::cout << "After swap:  a=" << a << " b=" << b << "\n";
    std::cout << "min(10, 20) = " << min(10, 20) << "\n";
    std::cout << "max(10, 20) = " << max(10, 20) << "\n\n";

    // 2. Doubles
    double x = 3.14, y = 2.71;
    std::cout << "=== Double tests ===\n";
    std::cout << "Before swap: x=" << x << " y=" << y << "\n";
    swap(x, y);
    std::cout << "After swap:  x=" << x << " y=" << y << "\n";
    std::cout << "min(3.14, 2.71) = " << min(3.14, 2.71) << "\n";
    std::cout << "max(3.14, 2.71) = " << max(3.14, 2.71) << "\n\n";

    // 3. Strings
    std::string s1 = "apple", s2 = "banana";
    std::cout << "=== String tests ===\n";
    std::cout << "Before swap: s1=" << s1 << " s2=" << s2 << "\n";
    swap(s1, s2);
    std::cout << "After swap:  s1=" << s1 << " s2=" << s2 << "\n";
    std::cout << "min(\"apple\", \"banana\") = " 
              << ::min(std::string("apple"), std::string("banana")) << "\n";
    std::cout << "max(\"apple\", \"banana\") = " 
              << ::max(std::string("apple"), std::string("banana")) << "\n\n";

    // 4. User-defined type (Point)
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    std::cout << "=== Point struct tests ===\n";
    std::cout << "Before swap: p1=(" << p1.x << "," << p1.y 
              << ") p2=(" << p2.x << "," << p2.y << ")\n";
    swap(p1, p2);
    std::cout << "After swap:  p1=(" << p1.x << "," << p1.y 
              << ") p2=(" << p2.x << "," << p2.y << ")\n";

    Point pmin = min(p1, p2);
    Point pmax = max(p1, p2);
    std::cout << "min(Point) = (" << pmin.x << "," << pmin.y << ")\n";
    std::cout << "max(Point) = (" << pmax.x << "," << pmax.y << ")\n";

    return 0;
}
