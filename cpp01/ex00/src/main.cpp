/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:40:50 by marcelodmac       #+#    #+#             */
/*   Updated: 2025/05/13 11:38:09 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"
#include "../inc/Zombie.h"

int main(void)
{
    Zombie *zombie;

    zombie = newZombie("potato");
    zombie->announce();
    delete zombie;
    randomChump("avocado");
    return (0);
}