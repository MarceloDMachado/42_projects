/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:40:50 by marcelodmac       #+#    #+#             */
/*   Updated: 2025/03/28 17:58:29 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.h"

int main(void)
{
    Zombie *zombie;

    zombie = newZombie("ueh");
    zombie->announce();
    delete zombie;
    randomChump("abacate");
    return (0);
}