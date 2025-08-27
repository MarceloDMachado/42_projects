/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:57:21 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/27 12:28:20 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./converter <string literal>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}