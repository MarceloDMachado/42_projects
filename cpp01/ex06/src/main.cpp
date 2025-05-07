/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:27:33 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/07 13:47:59 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl obj = Harl();
    
    if (argc != 2)
    {
        std::cerr << "Invalid arguments!\n";
        return (1);
    }
    obj.complain(argv[1]);
    
    return (0);
}