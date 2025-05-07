/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:27:33 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/06 21:54:32 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl obj = Harl();

    obj.complain("debug");
    obj.complain("info");
    obj.complain("warning");
    obj.complain("error");
    obj.complain("invalid");
    
    return 0;
}