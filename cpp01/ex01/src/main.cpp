/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:40:50 by marcelodmac       #+#    #+#             */
/*   Updated: 2025/03/28 16:39:14 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.h"

int main(void)
{
    Zombie *zombie;
    int     n;
    int     i;

    n = 5;
    zombie = zombieHorde(n, "potato");
    i = 0;
    while (i < n)
	{
		zombie[i++].announce();
	}
    // i = 0;
    // while (i < n)
    //     delete &zombie[i++];
	delete zombie;
    return (1);
}